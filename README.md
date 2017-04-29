# MOBOARD

Solves the basic types of Maneuvering Board problems.

When compiled on Linux, run with `./moboard [problem arg]`.
You will then receive a sequence of input prompts for the required data.

problem arg | function
----------- | --------
-c | Closest Point of Approach
-s | Stationing
-w | Wind

## Closest Point of Approach

This function solves a CPA problem using the following:

- Data from Own Ship
  - Course
  - Speed
  
- Data from Contact
  - Time 1
  - Range at Time 1
  - Bearing at Time 1
  - Time 2
  - Range at Time 2
  - Bearing at Time 2
  
The function outputs the following data:

- Range to CPA
- Bearing to CPA
- Time to CPA
- True Course of Contact
- True Speed of Contact

## Stationing

This function solves a Stationing problem using the following:

- Data from Own Ship
  - Course
  - Speed
  
- Data from Guide
  - Time 1
  - Range at Time 1
  - Bearing at Time 1
  - Time 2
  - Range at Time 2
  - Bearing at Time 2
  
- Stationing Data
  - Stationing speed
  - Stationing bearing (relative to guide)
  - Closest approach distance allowed
  
The function outputs the following data:

- Stationing course(s)
- Time to arrive on station

## Wind

This function solves a Wind problem.
