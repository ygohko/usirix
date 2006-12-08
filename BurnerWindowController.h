/*=========================================================================
  Program:   OsiriX

  Copyright (c) OsiriX Team
  All rights reserved.
  Distributed under GNU - GPL
  
  See http://homepage.mac.com/rossetantoine/osirix/copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.
=========================================================================*/




#import <Cocoa/Cocoa.h>

@class DRTrack;

@interface BurnerWindowController : NSWindowController {
	volatile BOOL burning;
	NSMutableArray *nodeArray;
	NSMutableArray *files, *anonymizedFiles;
	NSArray	*dbObjects;
	float burnSize;
	IBOutlet NSTextField *nameField;
	IBOutlet NSTextField *sizeField, *finalSizeField;
	IBOutlet NSMatrix	 *compressionMode;
	IBOutlet NSButton *burnButton;
	IBOutlet NSButton *anonymizedCheckButton;
	NSString *cdName;
	NSString *folderSize;
	NSTimer *burnAnimationTimer;
	int burnAnimationIndex;
	volatile BOOL runBurnAnimation;
	volatile BOOL isExtracting;
	volatile BOOL isSettingUpBurn;
	volatile BOOL isThrobbing;
	NSArray *filesToBurn;
	BOOL _releaseAfterBurn;
	BOOL _multiplePatients;
}
- (IBAction) setAnonymizedCheck: (id) sender;
- (id) initWithFiles:(NSArray *)theFiles;
- (id)initWithFiles:(NSArray *)theFiles managedObjects:(NSArray *)managedObjects releaseAfterBurn:(BOOL)releaseAfterBurn;
- (DRTrack*) createTrack;
-(IBAction)burn:(id)sender;
- (void)setCDTitle: (NSString *)title;
-(IBAction)setCDName:(id)sender;
-(NSString *)folderToBurn;
- (void)setFilesToBurn:(NSArray *)theFiles;
- (void)burnCD:(id)object;
- (NSArray *)extractFileNames:(NSArray *)filenames;
- (BOOL)dicomCheck:(NSString *)filename;
- (void)importFiles:(NSArray *)fileNames;
- (void)setup:(id)sender;
- (void)addDICOMDIRUsingDCMTK;
- (void)addDicomdir;
- (void)estimateFolderSize:(id)object;
- (void)performBurn:(id)object;
//- (void)reloadData:(id)object;
- (void)irisAnimation:(id)object;
- (void)throbAnimation:(id)object;

@end
