# Welcome to Wizardry
An introduction to Objective-C classes and objects

##What is a "class"
A class in Objective-C is the blueprint for something you wish to model and use in code. A class collects variables and defines operations (methods) that work with these variables. What you are modeling really doesn't matter. It could be a house, a football team, or whatever... If you can dream it, you can make a class for it!

##What is an "object"
An object is the actual implementation of a class. An object is to a class as a house is to a blueprint. Just like in real life, you use the blueprint that a class provides to make an object of a certain *type*

For a more in-depth discussion on objects, see [Ry's Objective-C Tutorial](http://rypress.com/tutorials/objective-c/classes)

##Creating a class
Classes are defined with a certain syntax. Much like our natural language has nouns and verbs that form sentences, we have certain code that defines a class. Classes are made up of two files, usually named <code>YourClassName</code>.h and <code>YourClassName</code>.m. An example of the code in these files for a house object can be seen below:

#####House.h
 ```objc
#import <Foundation/Foundation.h> //Import some foundational classes that we build ours from

@interface House : NSObject 

//Declare properties
@property int numberOfDoors;

//Declare methods here
- (void)printNumberOfDoors;

@end
 ```

#####House.m
 ```objc
#import "House.h"  //Import the Interface we just made

@implementation House //Define how the house works

- (void)printNumberOfDoors {
    NSLog(@"%d doors opened!", self.numberOfDoors);
}

@end
 ```
####Instantiating an Object
Just as blueprints for a house are useless if you never build it, so is a class if you never create (or **instantiate**) an object from it. Instantiating an object is like clearing the lot and building the house. It makes your house for you so you can access and manipulate it's variables.

To instantiate and object in Objective-C, make sure you have imported the class's <code>.h</code> file at the top of your page then do the following inside of a method.

```objc
House *myHouse = [[House alloc] init];
```

Ok, so let's break that down: 

You are (left side of the equal sign) 
creating an **instance** of type "House" called myHouse 

by (right side of the equals sign) allocating enough memory for a house (alloc) and initializing it (init). Don't worry about the square brackets quite yet. We will get to what they mean soon!

A real world analogy of <code>alloc</code> and <code>init</code> are clearing the space of a lot for a house and building the house, respectively.

####Accessing Properties
Now that we have created a house object, myHouse, we can access properties on that class. You can access properties like so:

```objc
int theNumberOfDoors = myHouse.numberOfDoors;
```

Any property on the class can be accessed by putting a dot after the name of the object and then the name of the property. Remember that properties can also be objects, so the dot notation chains all the way down. For instance, if there was a property of type <code>Address</code> named "address" in the house class, we could do something like <code>myHouse.address.zipCode</code>

##Methods
Sometimes there are operations that we need to associate with a class. These operations are called **methods** The example of the house class above has a method called <code>printNumberOfDoors</code>. It is a great example of defining a method with no inputs and not outputs. All it does is call for a line of code to run that prints out the number of doors.

It is not always the case, however that we want no inputs and no outputs. Sometimes we want to send something in and get something out of a method. An example of doing just that with addition and multiplication can be seen below:

 ```objc
 //An example of an "add" function in Objective-C
 //Takes in two integers and returns their sum
- (int)add:(int)number1 to:(int)number2 {
    return number1 + number2;
}

 //An example of an "multiplyBy2" function in Objective-C
 //Takes in a single integers and returns the integer multiplied by two
- (int)multiplyByTwo:(int)number {
    return number*2;
}

 ```
 
 A method generally follows the following pattern:
 
 -(**returnType**)<code>functionName</code>:(**firstParamType**)**firstParamName** <code>moreOfTheFunctionName</code>:(**secondParamType**)**secondParamName** .... 

####Return Types
Return types may be primitive types, like we talked about [last week](https://github.com/UH-300-021/LanguageDay), or objects. If it is an object, remember to add a * after the name. We will get why you need to do this at a later time.

```objc
//Primitive
-(double).....

//Object
-(House *)....
 ```

####Method inputs

Inputs can be primitives or objects as well. You follow the same rules
