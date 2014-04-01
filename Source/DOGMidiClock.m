//
//  DOGMidiClock.m
//  DOGMidiClock
//
//  Created by Vasco d'Orey on 01/04/14.
//  Copyright (c) 2014 Delta Dog. All rights reserved.
//

#import "DOGMidiClock.h"

@interface DOGMidiClock ()

@property (nonatomic, readwrite) NSUInteger bpm;
@property (nonatomic, readwrite) NSUInteger timeSignature;
@property (nonatomic, readwrite) NSUInteger ppqn;

- (id) initWithBPM:(NSUInteger)bpm timeSignature:(NSUInteger)timeSignature delegate:(id<DOGMidiClockDelegate>)delegate;

@end

@implementation DOGMidiClock
{
  NSUInteger _numberOfPulses;
}

#pragma mark - Lifecycle

+ (instancetype) midiClockWithBPM:(NSUInteger)bpm timeSignature:(NSUInteger)timeSignature delegate:(id<DOGMidiClockDelegate>)delegate
{
  return [[self alloc] initWithBPM:bpm timeSignature:timeSignature delegate:delegate];
}

- (id) initWithBPM:(NSUInteger)bpm timeSignature:(NSUInteger)timeSignature delegate:(id <DOGMidiClockDelegate>)delegate
{
  NSParameterAssert(bpm);
  NSParameterAssert(timeSignature);
  
  self = [super init];
  if(!self) return nil;
  
  _bpm = bpm;
  _timeSignature = timeSignature;
  _delegate = delegate;
  _ppqn = 96;
  
  return self;
}

#pragma mark - Metronome

- (void) start
{
}

- (void) pause
{
}

- (void) resume
{
}

- (void) stop
{
}

@end
