/*
 * Copyright 2022 University of Michigan EECS183
 *
 * test.cpp
 * Project UID 28eb18c2c1ce490aada441e65559efdd
 *
 * Final Project - Elevators
 */
 
////////////////////////////////////////////////
// You will submit test.cpp to the autograder //
// FOR LAB 8, but NOT the final project Core  //
////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>
#include "AI.h"
#include "Building.h"
#include "BuildingState.h"
#include "Elevator.h"
#include "Floor.h"
#include "Game.h"
#include "Move.h"
#include "Person.h"
#include "SatisfactionIndex.h"
#include "Utility.h"

using namespace std;

// declare your test functions here
void person_tests();
void elevator_tests();
void start_tests() {
    // call your test functions here
    person_tests();
    elevator_tests();
    return;
}
// write test functions here
void person_tests() {
    //initialize a person with targetFloor 5, anger 5
    Person p("0f0t5a5");
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 5" << endl;
    //simulate time being a multiple of TICKS_PER_ANGER_INCREASE
    bool exploded = p.tick(TICKS_PER_ANGER_INCREASE);
    cout << exploded << " Expected 0" << endl;
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;
    //simulate time not being a multiple
    p.tick(TICKS_PER_ANGER_INCREASE - 1);
    //no change
    p.tick(2);
    p.print(cout);
    cout << p.getTargetFloor() << " " << p.getAngerLevel() << " Expected 5 6" << endl;
    p.tick(TICKS_PER_ANGER_INCREASE); //7 after
    cout << p.getAngerLevel() << endl;
    cout << "Expected: f0t5a7, actual: ";
    p.print(cout);
    cout << endl;
    p.tick(TICKS_PER_ANGER_INCREASE); //8 after
    cout << p.getAngerLevel() << endl;
    p.tick(TICKS_PER_ANGER_INCREASE); //9 after
    cout << p.getAngerLevel() << endl;
    exploded = p.tick(TICKS_PER_ANGER_INCREASE);
    cout << exploded << " Expected 1" << endl;
    Person p2("1f2t3a4");
    cout << "Expected: f2t3a4, actual: ";
    p2.print(cout);
}

void elevator_tests() {
    cout << endl << "Now testing elevator tests" << endl;
    Elevator e1;
    e1.print(cout);
    e1.serviceRequest(3);
    e1.tick(TICKS_PER_ELEVATOR_MOVE);
    cout << "Expected: 1s3, actual: ";
    e1.print(cout);
    cout << endl;
    cout << "Expected: 1, actual: " << e1.getCurrentFloor() << endl;
    cout << "Expected: 3, actual: " << e1.getTargetFloor() << endl;
    cout << "Expected: 1, actual: " << e1.isServicing() << endl;
    e1.tick(TICKS_PER_ELEVATOR_MOVE);
    e1.tick(TICKS_PER_ELEVATOR_MOVE);
    cout << "Expected: 0, actual: " << e1.isServicing() << endl;
    e1.serviceRequest(1);
    e1.tick(TICKS_PER_ELEVATOR_MOVE);
    cout << "Expected: 2, actual: " << e1.getCurrentFloor() << endl;
    e1.print(cout);
    Elevator e2;
    e2.tick(3);
    e2.print(cout);
    cout << "Expected: 0s0, actual: ";
}



// write test functions here
