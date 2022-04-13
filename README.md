# Documentation

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`class `[`Motor`](#class_motor) | 

# class `Motor` 

## Summary

 Members                        | Descriptions                                
--------------------------------|---------------------------------------------
`public inline int `[`speed`](#class_motor_1a783b20d824e9d5e9d3b39407657c06b5)`() const` | 
`public inline boolean `[`direction`](#class_motor_1a0d1e9109147a1620ba2231572f64502d)`() const` | 
`public  `[`Motor`](#class_motor_1ab90424518c4826de76d15488ca90aeb6)`(const unsigned int forwardPin,const unsigned int backwardPin)` | Contructor of [Motor](#class_motor). 
`public void `[`control`](#class_motor_1a2efba88aedaeaab3280432b8bbe8d874)`(int throttle)` | Throttle the [Motor](#class_motor) using integer value between -255 and 255. 
`public void `[`reverse`](#class_motor_1a1e1cfdd2808f7cb6a3816b8089e135db)`()` | Reverse the [Motor](#class_motor) direction.
`public void `[`setDirection`](#class_motor_1a20f404b9f19e3bd9b24f65cfa093da8c)`(boolean direction)` | Change the [Motor](#class_motor) direction. 
`public void `[`setSpeed`](#class_motor_1a52629377895ffd22fdd60f648cb86f1a)`(unsigned int speed)` | Change the [Motor](#class_motor) speed. 

## Members

#### `public inline int `[`speed`](#class_motor_1a783b20d824e9d5e9d3b39407657c06b5)`() const` 

#### `public inline boolean `[`direction`](#class_motor_1a0d1e9109147a1620ba2231572f64502d)`() const` 

#### `public  `[`Motor`](#class_motor_1ab90424518c4826de76d15488ca90aeb6)`(const unsigned int forwardPin,const unsigned int backwardPin)` 

Contructor of [Motor](#class_motor). 
#### Parameters
* `forwardPin` : forward pin of the motor (forward direction control) 

* `backwardPin` : backward pin of the motor (backward direction control)

#### `public void `[`control`](#class_motor_1a2efba88aedaeaab3280432b8bbe8d874)`(int throttle)` 

Throttle the [Motor](#class_motor) using integer value between -255 and 255. 
#### Parameters
* `throttle` : Integer between -255 and 255 (-255 : 100% backward, 255 : 100% forward).

#### `public void `[`reverse`](#class_motor_1a1e1cfdd2808f7cb6a3816b8089e135db)`()` 

Reverse the [Motor](#class_motor) direction.

#### `public void `[`setDirection`](#class_motor_1a20f404b9f19e3bd9b24f65cfa093da8c)`(boolean direction)` 

Change the [Motor](#class_motor) direction. 
#### Parameters
* `direction` : Boolean representing the new direction (true : Forward, false : Backward)

#### `public void `[`setSpeed`](#class_motor_1a52629377895ffd22fdd60f648cb86f1a)`(unsigned int speed)` 

Change the [Motor](#class_motor) speed. 
#### Parameters
* `speed` : Integer between 0 and 255 (-255 : Slowest, 255 : Fastest).
