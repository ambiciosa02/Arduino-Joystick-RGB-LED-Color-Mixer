# Arduino-Joystick-RGB-LED-Color-Mixer
This Arduino sketch is a Joystick-controlled RGB LED color mixer. It allows you to adjust the red, green, and blue components of an RGB LED using a joystick.

🔍 How it works
1️⃣ Hardware setup

Joystick:

VRx → A0 (horizontal, unused here)

VRy → A1 (vertical, controls color intensity)

SW → 2 (push button, switches color channel)

RGB LED (common cathode assumed):

RED → pin 9

GREEN → pin 10

BLUE → pin 11

2️⃣ Program flow

Setup:

Initialize joystick button as INPUT_PULLUP.

Initialize RGB pins as OUTPUT.

Start Serial Monitor to display RGB values.

Set initial color to medium gray (128,128,128).

Loop:

Read joystick vertical axis (y = analogRead(VRy)).

Check joystick button press to cycle the mode:

0 = adjust red

1 = adjust green

2 = adjust blue

Determine adjustment (delta = ±5) based on vertical movement.

Constrain the color value between 0 and 255.

Update the RGB LED with analogWrite().

Print the current RGB values to Serial Monitor for debugging.

3️⃣ What you’ll see

Moving joystick up or down changes the intensity of the selected color.

Pressing the joystick button switches the color channel.

Serial Monitor shows current R, G, B values.
