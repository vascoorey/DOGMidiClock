//
//  DOGMidiClock.h
//  DOGMidiClock
//
//  Created by Vasco d'Orey on 01/04/14.
//  Copyright (c) 2014 Delta Dog. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol DOGMidiClockDelegate;

typedef struct
{
  //! @abstract The current beat
  unsigned long currentBeat;
  //! @abstract Three-eights of the current beat.
  short threeEights;
  //! @abstract The current number of elapsed pulses.
  unsigned long long pulses;
} DOGNoteInformation;

@interface DOGMidiClock : NSObject

@property (nonatomic, weak) id <DOGMidiClockDelegate> delegate;

//! @abstract Creates a new midi clock with the desired BPM, time signature & delegate
+ (instancetype) midiClockWithBPM:(NSUInteger)bpm timeSignature:(NSUInteger)timeSignature delegate:(id <DOGMidiClockDelegate>)delegate;

//! @abstract The time from which the midi clock is relative to (i.e. started at)
@property (nonatomic, readonly) NSTimeInterval startTime;

//! @abstract The number of beats per minute
@property (nonatomic, readonly) NSUInteger bpm;

//! @abstract The number of beats per bar (i.e. 1, 2, 3, 4, 5, ...)
@property (nonatomic, readonly) NSUInteger timeSignature;

//! @abstract Pulses per quarter note.
@property (nonatomic, readonly) NSUInteger ppqn;

//! @abstract Starts the midi clock. This will fire off a tight loop in a high priority thread.
- (void) start;

//! @abstract Pauses the midi clock.
- (void) pause;

//! @abstract Resumes the midi clock.
- (void) resume;

//! @abstract Stops the midi clock.
- (void) stop;

@end

@protocol DOGMidiClockDelegate <NSObject>

@optional

//Lifecycle
- (void) midiClockWillStart:(DOGMidiClock *)midiClock;
- (void) midiClockDidStart:(DOGMidiClock *)midiClock;
- (void) midiClockWillStop:(DOGMidiClock *)midiClock;
- (void) midiClockDidStop:(DOGMidiClock *)midiClock;

//Beats
- (void) midiClock:(DOGMidiClock *)midiClock didBeatWithNoteInformation:(DOGNoteInformation)noteInformation;

@end
