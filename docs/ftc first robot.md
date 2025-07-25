# Rev Robotics Control Hub
[Rev Robotics Control Hub](https://www.revrobotics.com/rev-31-1595/) and [expansion hub](https://www.revrobotics.com/rev-31-1153/). Control hub [users manual](https://docs.revrobotics.com/duo-control). 


# Sample using touch sensor
To use the touch sensor, plug into the **0-1** port on the **control hub**. In the **driver station** select the **ellipse menu > configure robot > new** and **control hub > control hub > digital devices** and set **device 1** to **REV Touch Sensor**. 

> You can't use port 0 for a touch sensor. A REV Robotics Touch Sensor must be configured on digital port number 1, 3, 5, or 7.

Once setup and activated, go back to the main screen. On the **robot controller console on your PC** you will be using the `TouchSensor` object.

The following example was created by clicking the **add file plus icon** and selecting the **Sensor Touch** example. 

```java
/* Copyright (c) 2017 FIRST. All rights reserved. */

package org.firstinspires.ftc.teamcode;

import com.qualcomm.robotcore.eventloop.opmode.Disabled;
import com.qualcomm.robotcore.eventloop.opmode.LinearOpMode;
import com.qualcomm.robotcore.eventloop.opmode.TeleOp;
import com.qualcomm.robotcore.hardware.TouchSensor;

/*
 * This OpMode demonstrates how to use a REV Robotics Touch Sensor, REV Robotics Magnetic Limit Switch, or other device
 * that implements the TouchSensor interface. Any touch sensor that connects its output to ground when pressed
 * (known as "active low") can be configured as a "REV Touch Sensor". This includes REV's Magnetic Limit Switch.
 *
 * The OpMode assumes that the touch sensor is configured with a name of "sensor_touch".
 *
 * A REV Robotics Touch Sensor must be configured on digital port number 1, 3, 5, or 7.
 * A Magnetic Limit Switch can be configured on any digital port.
 *
 * Use Android Studio to Copy this Class, and Paste it into your team's code folder with a new name.
 * Remove or comment out the @Disabled line to add this OpMode to the Driver Station OpMode list.
 */
@TeleOp(name = "Sensor: REV touch sensor", group = "Sensor")
public class SensorTouch extends LinearOpMode {
    TouchSensor touchSensor;  // Touch sensor Object

    @Override
    public void runOpMode() {

        // get a reference to our touchSensor object.
        touchSensor = hardwareMap.get(TouchSensor.class, "sensor_touch");

        // wait for the start button to be pressed.
        waitForStart();

        // while the OpMode is active, loop and read whether the sensor is being pressed.
        // Note we use opModeIsActive() as our loop condition because it is an interruptible method.
        while (opModeIsActive()) {

            // send the info back to driver station using telemetry function.
            if (touchSensor.isPressed()) {
                telemetry.addData("Touch Sensor", "Is Pressed");
            } else {
                telemetry.addData("Touch Sensor", "Is Not Pressed");
            }

            telemetry.update();
        }
    }
}
```

#robot #first #ftc
{"created":"2024-01-17 15:11"}
