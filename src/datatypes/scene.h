//
//  scene.h
//  C-ray
//
//  Created by Valtteri Koskivuori on 28/02/2015.
//  Copyright © 2015-2020 Valtteri Koskivuori. All rights reserved.
//

#pragma once

#include "color.h"

struct renderer;

/// World
struct world {
	//Ambient background color.
	struct gradient ambientColor;
	
	//Optional environment map
	struct envMap *hdr;
	
	//3D models
	struct mesh *meshes;
	int meshCount;
	
	struct instance *instances;
	int instanceCount;
	
	struct bvh *topLevel;
	
	//Spheres
	struct sphere *spheres;
	int sphereCount;
	
	//Currently only one camera supported
	struct camera *camera;
	int cameraCount;
	
	struct block *nodePool;
};

int loadScene(struct renderer *r, char *input);

void destroyScene(struct world *scene);
