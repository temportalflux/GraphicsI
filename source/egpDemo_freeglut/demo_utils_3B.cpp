#include "demo_utils.h"


#include "GL/glew.h"




//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
// PART 2A: create interleaved VBO
unsigned int demo::createInterleavedVBO(unsigned int numVerts, unsigned int attribCount, const float **data)
{
	const unsigned int sizeoffloat = sizeof(float);
	const unsigned int floatsPerAttrib = 3;

	// validate
	if ((numVerts > 0) && (attribCount > 0) && (attribCount <= ATTRIB_COUNT) && (data))
	{
		
		// create
		unsigned int handle;
		glGenBuffers(1, &handle);

		// bind
		glBindBuffer(GL_ARRAY_BUFFER, handle);

		// create giant array for all the things (attribute data)
		// number of floats = numVerts * numAttribs * numFloatsPerAttrib
		unsigned int numFloats = numVerts * attribCount * floatsPerAttrib;

		float *interleavedData = new float[numFloats];

		// num floats for single vertex
		unsigned int floatsPerVertex = attribCount * floatsPerAttrib;

		// *giant sorting algorithm*
		// iterate through attribs and copy data
		// count attribs, index to where each attrib starts
		for (unsigned int i = 0, attribStart = 0;
			i < attribCount;
			++i, attribStart += floatsPerAttrib) {
			
			const float *dataPtr = data[i];

			for (unsigned int j = 0,
				interleavedIndex = attribStart, rawDataIndex = 0;
				j < numVerts;
				++j, interleavedIndex += (floatsPerVertex - floatsPerAttrib)) {

				// copy data
				for (unsigned int n = 0; n < 3; n++)
					interleavedData[interleavedIndex++] = dataPtr[rawDataIndex++];

			}

		}

		glBufferData(GL_ARRAY_BUFFER, (numFloats * sizeoffloat), interleavedData, GL_STATIC_DRAW);

		// unbind
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// delete after unbind to make sure the data is set AFTER bind is done
		delete[] interleavedData;

	}
	return 0;
}

void demo::drawInterleavedVBO(unsigned int numVerts, unsigned int attribCount, 
	unsigned int primType, unsigned int handle, const unsigned int *attribIndex)
{
	const unsigned int sizeoffloat = sizeof(float);
	const unsigned int floatsPerAttrib = 3;

	if ((numVerts > 0) && (attribCount > 0) && (attribCount <= ATTRIB_COUNT) && 
		handle && attribIndex)
	{
		
	}
}

void demo::deleteBufferObject(unsigned int handle)
{
	if (handle)
	{
		glDeleteBuffers(1, &handle);
	}
}



//-----------------------------------------------------------------------------
// PART 2B: tie interleaved VBO to VAO and draw VAO
unsigned int demo::createVAO(unsigned int numVerts, unsigned int attribCount, 
	const float **data, const unsigned int *attribIndex, unsigned int *vboHandleOut)
{
	const unsigned int sizeoffloat = sizeof(float);
	const unsigned int floatsPerAttrib = 3;

	if (vboHandleOut)
	{
		
	}
	
	// fail
	return 0;
}

void demo::drawVAO(unsigned int numVerts, unsigned int primType, unsigned int vaoHandle)
{
	// the VAO is already configured, so just bind it and call draw!
	if (numVerts && vaoHandle)
	{
		
	}
}

void demo::deleteVAO(unsigned int handle)
{
	if (handle)
	{
		
	}
}



//-----------------------------------------------------------------------------
// PART 2C: create VAO with IBO
unsigned int demo::createIndexedVAO(unsigned int numVerts, unsigned int numIndices, 
	unsigned int attribCount, const float **data, const unsigned int *attribIndex, 
	const unsigned int *indexData, unsigned int *vboHandleOut, unsigned int *iboHandleOut)
{
	return 0;
}

void demo::drawIndexedVAO(unsigned int numIndices, unsigned int primType, 
	unsigned int indexType, unsigned int vaoHandle)
{
	if (numIndices && vaoHandle)
	{
		
	}
}



//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
