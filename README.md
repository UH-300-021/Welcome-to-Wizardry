# Welcome to Wizardry
An introduction to Objective-C classes and objects

##What is a "class"
A class in Objective-C is the blueprint for something you wish to model and use in code. A class collects properties and defines operations (methods) that work with these properties. What you are modeling really doesn't matter. It could be a house, a football team, or whatever... If you can dream it, you can make a class for it!

##What is an "object"
An object is the actual implementation of a class. An object is to a class as a house is to a blueprint. Just like in real life, you use the blueprint that a class provides to make an object of a certain *type*

For a more in-depth discussion on objects, see [Ry's Objective-C Tutorial](http://rypress.com/tutorials/objective-c/classes)

##Creating a class
Classes are defined with a certain syntax. Much like our natural language has nouns and verbs that form sentences, we have certain code that defines a class. Classes are made up of two files, usually named <code>YourClassName</code>.h and <code>YourClassName</code>.m. An example of the code in these files for a house object can be seen below:

#####House.h
 ```objc
#import <Foundation/Foundation.h> //Import some foundational classes that we build ours from

@interface House : NSObject {  //Declare a House object
    //Variables go here
    int numberOfDoors;
}

//Declare methods here
- (void)openDoor;

@end
 ```

#####House.m
 ```objc
#import "House.h"  //Import the Interface we just made

@implementation House //Define how the house works

- (void)openDoor {
    NSLog(@"%d doors opened!", numberOfDoors);
}

@end
 ```
