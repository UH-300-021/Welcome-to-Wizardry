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
Return types may be primitive types, like we talked about [in the last lesson](https://github.com/UH-300-021/LanguageDay), or objects. If it is an object, remember to add a * after the name. We will get why you need to do this at a later time.

```objc
//Primitive
-(double).....

//Object
-(House *)....
 ```

####Method inputs

Inputs can be primitives or objects as well. You follow the same rules

##Inheritance
When we model systems, makes sense for something to be contained inside something else. Think about how Houses are contained in Neighborhoods which are contained in Cities, etc. Sometimes, however, we need to build a class that is _a kind of_ another. For instance, a Mansion is a kind of House. So is an Apartment. What makes a Mansion and an Apartment similar may attributes like living space, windows and doors. These are common to all Houses. 

But Mansions and Apartments may differ in that a Mansion has a pool and a basketball court (amongst other things). We would call the Mansion and the Apartment **Subclasses** of House. They **inherit** everything about a house (its properties and methods), but are free to contain additional properties and methods that better describe it.

An example of the Mansion class can be seen below:

 ```objc
#import "House.h" //Import House so you can inherit from it

@interface Mansion : House 

//Declare properties
@property Pool *pool;
@property BasketballCourt *basketballCourt;

//Declare methods here
- (void)startHouseParty;

@end
 ```

##Collections
Keeping track of objects that you have made can sometimes be difficult. Image a situation where you have a lot of objects and you want to list them in a table. Wouldn't it be cool if there were objects that kept track of other objects? Fortunately, there is! These types of objects are called **collections**. The main collection classes we will use are <code>NSArray</code>, <code>NSMutableArray</code>, <code>NSDictionary</code>, and <code>NSMutableDictionary</code>.

###NSArray
Arrays hold objects and are accessed linearly. Think about it like a number line where each tick on the number line contains an object. Below we will cover how to make an array and how to access its contents.

#####Building an array
To create an array of strings named "colorsArray", you would write the following:

```objc
NSArray *colorsArray = [[NSArray alloc] initWithObjects: @"Red", @"Blue", @"Green", nil];
 ```
 
 We make arrays so often, there is also a way of writing them shorthand. (Highly recommended)
 ```objc
NSArray *colorsArray = @[@"Red", @"Blue", @"Green"];
 ```

A string is just one type of object, but Arrays can hold any kind of object, even an Array! Below we will create an array of house objects.

 ```objc
 House *house1 = [[House alloc] init];
 
 House *house2 = [[House alloc] init];
 
NSArray *houses = @[house1, house2];
 ```
 
 #####Accessing Elements in an Array
To access elements in an array, we use request the object at a specific **index**. The index is like the place on our number line. Array indexes begin at 0, not 1, so <code>house1</code> above is stored at index 0 of the houses array and <code>house2</code> is stored at index 1. An example of accessing them can be seen below:

 ```objc
 House *house1 = houses[0];
 
 House *house2 = houses[1];
 ```
