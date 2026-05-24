%% Ideal BLDC 6-step: i_a/i_b/i_c + RPM + Thrust (calibrated)
clear; clc; close all;

% ---------- Measured full-throttle point ----------
rpm_full   = 17498;          % RPM @ 100% throttle
thrust_g   = 2500;           % grams of thrust at full throttle
Vbus       = 22.2;           % V (not used in ideal plots, for reference)
Idc_full   = 32.5;           % A (use as plateau phase current, idealized)

% ---------- Plot & motor settings ----------
p        = 7;                % pole pairs
Ipk      = Idc_full;         % A, plateau current in conducting phases (ideal)
tau      = 0.25;             % s, speed time constant
t_end    = 1.5;              % s, long enough to reach steady state
dt       = 1e-4;             % s, plot resolution

% ---------- Time + ideal speed step ----------
t   = (0:dt:t_end)';                   % time vector
rpm = rpm_full * (1 - exp(-t/tau));    % first-order rise to rpm_full
wm  = rpm * (2*pi/60);                 % rad/s (mechanical)
theta_m = cumtrapz(t, wm);             % mechanical angle [rad]
theta_e = mod(p * theta_m, 2*pi);      % electrical angle [0, 2π)

% ---------- Ideal 120° conduction phase currents ----------
sec = floor(theta_e/(pi/3)) + 1;       % sector 1..6
map = [ 1 -1  0;
        1  0 -1;
        0  1 -1;
       -1  1  0;
       -1  0  1;
        0 -1  1];

ia = zeros(size(t)); ib = ia; ic = ia;
for k = 1:6
    m = (sec == k);
    ia(m) = Ipk * map(k,1);
    ib(m) = Ipk * map(k,2);
    ic(m) = Ipk * map(k,3);
end

% ---------- Thrust calibration so T = 3072 g at 17498 RPM ----------
n_full   = rpm_full/60;                 % rev/s
T_full_N = thrust_g/1000 * 9.81;        % N
kT       = T_full_N / (n_full^2);       % T = kT * n^2
n        = rpm/60;                      % rev/s over time
Thrust_N = kT * n.^2;                   % N
Thrust_g = Thrust_N / 9.81 * 1000;      % grams

% ---------------------------- Plots ----------------------------
% Phase currents (all in one axes)
figure('Name','Three Phase Current Consumption');
plot(t, ia, 'LineWidth',1.2); hold on; grid on;
plot(t, ib, 'LineWidth',1.2);
plot(t, ic, 'LineWidth',1.2);
xlabel('Time (s)'); ylabel('Phase current (A)');
title('Three Phase Current Consumption');
legend('i_a','i_b','i_c','Location','best');

% Thrust (grams), with target line at 3072 g
figure('Name','Generated Thrust');
plot(t, Thrust_g, 'LineWidth',1.6); grid on; hold on;
yline(thrust_g,'k--','3072 g');
xlabel('Time (s)'); ylabel('Thrust (g)');
title('Thrust vs time');

% RPM (now plotted)
figure('Name','Angular Speed over time');
plot(t, rpm, 'LineWidth',1.6); grid on; hold on;
yline(rpm_full,'k--',sprintf('%d RPM', rpm_full));
xlabel('Time (s)'); ylabel('Speed (RPM)');
title(sprintf('Motor Angular Speed', rpm_full, tau));
