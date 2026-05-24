# 🚁 FloodLink: Autonomous Aerial Delivery System

**An Advanced UAV System for Flood Disaster Response & Emergency Logistics**

![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)
![Platform](https://img.shields.io/badge/Platform-MATLAB%20%7C%20Arduino-orange.svg)
![Status](https://img.shields.io/badge/Status-Active-brightgreen.svg)

---

## 📌 Overview

**FloodLink** is an autonomous aerial delivery system engineered specifically for rapid disaster response in flood-affected regions. When severe flooding paralyzes ground transportation, establishing reliable, airborne supply chains becomes a critical lifeline for delivering emergency rations, medical supplies, and communication equipment.

This repository encompasses the developmental pipeline of the FloodLink quadcopter, focusing heavily on robust mission planning, real-time telemetry feedback, and rigorous payload safety logic to ensure successful deliveries in unpredictable and hazardous environments.

---

## ✨ Key Features

* **Autonomous Mission Planning:** Intelligent routing systems designed to navigate safely to predefined coordinates within flood zones.
* **Dynamic Payload Safety Logic:** Integrated load sensing ensures the UAV operates within strict weight thresholds, maintaining aerodynamic stability and preventing mid-air motor failures.
* **Real-Time Telemetry Feedback:** Continuous data processing for flight parameters, spatial orientation, and system health.
* **Comprehensive 3D Simulations:** Advanced MATLAB and Simulink models for rigorous pre-flight testing of motor dynamics and UAV movement under varying environmental stresses.
* **Hardware Interfacing:** Custom microcontroller integration for precise payload weight calibration and monitoring during the drop-off sequence.

---

## 📂 Repository Structure

The repository contains the essential source code, simulation models, and visualizations required to understand and test the FloodLink system:

```text
├── README.md                           # Project documentation
├── LICENSE                             # MIT License
├── floodlink_system connections.html   # Interactive system schematic and wiring diagram
├── loadsensor.ino                      # C++ source code for real-time payload weight processing
├── graph.m                             # MATLAB script for telemetry and performance plotting
├── graph.m.txt / graph2.m.txt ...      # Exported raw telemetry and simulation data
├── motSim.slx.zip                      # Simulink model: Quadcopter motor dynamics
└── uavMovement.slx.zip                 # Simulink model: Autonomous trajectory & kinematics
