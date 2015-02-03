//
//  House.h
//  WelcomeToWizardy
//
//  Created by UH 300 -21 on 2/3/15.
//  Copyright (c) 2015 UH 300 -21. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "Address.h"

@interface House : NSObject

//Properties
@property int numberOfDoors;
@property int numberOfWindows;
@property NSString *name;

@property Address *address;

//Methods
-(void)printHouseInfo;
@end
