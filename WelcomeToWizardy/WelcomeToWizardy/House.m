//
//  House.m
//  WelcomeToWizardy
//
//  Created by UH 300 -21 on 2/3/15.
//  Copyright (c) 2015 UH 300 -21. All rights reserved.
//

#import "House.h"

@implementation House

-(void)printHouseInfo {
    NSLog(@"%d", self.numberOfDoors);
    NSLog(@"%d", self.numberOfWindows);
    NSLog(self.name);
}

@end
