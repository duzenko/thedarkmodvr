/*****************************************************************************
                    The Dark Mod GPL Source Code
 
 This file is part of the The Dark Mod Source Code, originally based 
 on the Doom 3 GPL Source Code as published in 2011.
 
 The Dark Mod Source Code is free software: you can redistribute it 
 and/or modify it under the terms of the GNU General Public License as 
 published by the Free Software Foundation, either version 3 of the License, 
 or (at your option) any later version. For details, see LICENSE.TXT.
 
 Project: The Dark Mod (http://www.thedarkmod.com/)
 
 $Revision: 6564 $ (Revision of last commit) 
 $Date: 2015-12-26 03:47:35 +0000 (Sat, 26 Dec 2015) $ (Date of last commit)
 $Author: grayman $ (Author of last commit)
 
******************************************************************************/

#ifndef __AI_PATH_WAIT_TASK_H__
#define __AI_PATH_WAIT_TASK_H__

#include "PathTask.h"

namespace ai
{

// Define the name of this task
#define TASK_PATH_WAIT "PathWait"

class PathWaitTask;
typedef boost::shared_ptr<PathWaitTask> PathWaitTaskPtr;

class PathWaitTask :
	public PathTask
{
private:
	// The game time at which waiting ends in ms.
	float _endtime;

	PathWaitTask();
public:
	PathWaitTask(idPathCorner* path);

	// Get the name of this task
	virtual const idStr& GetName() const;

	// Override the base Init method
	virtual void Init(idAI* owner, Subsystem& subsystem);

	virtual bool Perform(Subsystem& subsystem);

	virtual void OnFinish(idAI* owner); // grayman #4046

	// Save/Restore methods
	virtual void Save(idSaveGame* savefile) const;
	virtual void Restore(idRestoreGame* savefile);

	// Creates a new Instance of this task
	static PathWaitTaskPtr CreateInstance();
};

} // namespace ai

#endif /* __AI_PATH_WAIT_TASK_H__ */
