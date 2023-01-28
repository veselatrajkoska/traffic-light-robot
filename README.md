# Traffic light robot

This is a simple Arduino project for the course Introduction to Robotics. 

The project consists of a standard traffic light sensor, an additional light sensor next to the traffic light, and a distance sensor installed opposite the traffic light, looking in the direction of the line where cars should be where the red light is on.

If a car tries to pass before it is allowed (while the light is red or yellow), the distance sensor loads a distance that is less than the constant distance to the traffic light (when there are no obstacles). The additional light sensor next to the traffic light immediately starts flashing, signaling that an illegal crossing is taking place, until the car moves away.

A video demonstrating the full functionalities of the robot is posted on this link: https://youtube.com/shorts/IkTiwD9dVvM?feature=share.
