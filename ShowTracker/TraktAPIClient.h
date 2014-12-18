//
//  TraktAPIClient.h
//  ShowTracker
//
//  Created by Óscar Calles Sáez on 17/12/14.
//  Copyright (c) 2014 Ray Wenderlich. All rights reserved.
//

/*
 
 TraktAPIClient will make it easier to access the trakt API 
 and make a lot of requests to the same base URL,
 using the same API key. 
 This also encapsulates all the networking calls
 and responsibility into a single class.
 
 */


// Import the main header for AFNetworking,
// which is AFNetworking.h. This includes AFHTTPSessionManager,
// which will be the super class of TraktAPIClient,
// and other related networking classes.
#import <AFNetworking/AFNetworking.h>

// declare two string constants with the extern modifier.
// This means these strings will be globally available.
extern NSString * const kTraktAPIKey;
extern NSString * const kTraktBaseURLString;

// TraktAPIClient extend AFHTTPSessionManager
@interface TraktAPIClient : AFHTTPSessionManager

// Declare the Class Method (+) sharedClient,
// which will return a singleton instance for TraktAPIClient.
+ (TraktAPIClient *)sharedClient;

// Declare a Instance Method (-) or helper method
// that will make it easier to use the trakt API
// to get shows for a specific date, username, and number of days.
- (void)getShowsForDate:(NSDate *)date
               username:(NSString *)username
           numberOfDays:(int)numberOfDays
                success:(void(^)(NSURLSessionDataTask *task, id responseObject))success
                failure:(void(^)(NSURLSessionDataTask *task, NSError *error))failure;

@end
