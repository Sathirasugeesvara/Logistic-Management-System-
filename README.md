# 🚚 Logistics Management System (C Programming Project) 
**Language:** C  

---

## 🎯 Project Objective

The objective of this project is to **design and implement a menu-driven logistics management system** using the **C programming language**.  
The program simulates a basic delivery management system that handles **cities**, **routes**, **vehicle types**, **delivery requests**, **cost estimation**, and **performance reporting**.

---

## 🧠 Key Concepts Used

- Arrays  
- Functions  
- Loops  
- Conditional Statements  
- File Handling (for extra marks)  

---

## 🧩 System Functional Requirements

### 1. City Management
- Store **up to 30 cities** (e.g., Colombo, Kandy, Galle, Jaffna, etc.)  
- Each city must have a **unique name**  
- Menu options include:
  - Add a new city  
  - Rename or remove a city  

---

### 2. Distance Management
- Store intercity distances in a **2D array**  
  ```c
  int distance[MAX_CITIES][MAX_CITIES];
  ```
- Features:
  - Input or edit distances between two cities  
  - Prevent distance from city → itself (set to 0)  
  - Automatically ensure distance symmetry  
  - Display a formatted distance table  

---

### 3. Vehicle Management

| Vehicle Type  |  Capacity (kg) | Rate (LKR/km)  | Avg Speed (km/h)  | Fuel Efficiency (km/l)   |
|---------------|----------------|----------------|-------------------|--------------------------|
| Van           | 1,000          | 30             | 60                | 12                       |
| Truck         | 5,000          | 40             | 50                | 6                        |
| Lorry         | 10,000         | 80             | 45                | 4                        |

The user must select a vehicle type when estimating cost.

---

### 4. Delivery Request Handling
Each order includes:
- Source city  
- Destination city  
- Weight (in kg)  
- Vehicle type (1=Van, 2=Truck, 3=Lorry)  

**Validation:**
- Weight ≤ vehicle capacity  
- Source ≠ Destination  

---

### 5. Cost, Time, and Fuel Calculations

Let:  
- `D` = Distance (km)  
- `W` = Weight (kg)  
- `R` = Rate (LKR/km)  
- `S` = Speed (km/h)  
- `E` = Efficiency (km/l)  
- `F` = Fuel Price (LKR/l)  

#### Formulas
```
DeliveryCost = D × R × (1 + W / 10000)
Time = D / S
FuelUsed = D / E
FuelCost = FuelUsed × F
TotalCost = DeliveryCost + FuelCost
Profit = DeliveryCost × 0.25
CustomerCharge = TotalCost + Profit
```

---

### 6. Delivery Records
- Maintain up to **50 deliveries** in arrays.  

---

### 7. Least-Cost Route Calculation
Implement an algorithm to find the **least-cost or shortest route** between two cities.  

- Generate all possible route permutations (≤ 4 cities).  
- Calculate total distance for each route.  
- Select the minimum distance route.  
- Use this route for further cost calculations.  

---

### 8. Performance Reports
Include a menu option **"Reports"** showing:
- Total Deliveries Completed  
- Total Distance Covered  
- Average Delivery Time  
- Total Revenue and Profit  
- Longest and Shortest Routes Completed  

---

### 9. File Handling (Extra Marks)
Use `.txt` files to store and load persistent data.

**Examples:**
- `routes.txt` → City list and distance matrix  
- `deliveries.txt` → Delivery history and cost details  

**Program should:**
- Load existing files on startup  
- Save data before exiting  

---

## 🧰 Technologies & Tools

- **C Language** (Code::Blocks / GCC)
- **Git & GitHub**
- **Text Files** for persistence

---
