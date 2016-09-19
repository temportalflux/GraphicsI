#include "demo_utils.h"


#include "GL/glew.h"



void demo::drawTestTriangle()
{
	// immediate mode coloured triangle... DO NOT USE IMMEDIATE MODE!!!!
	glBegin(GL_TRIANGLES);
		glColor3f( 1.0f, 0.0f, 0.0f   );
		glVertex3f(-0.4f, -0.5f, -0.5f);
		glColor3f( 0.0f, 1.0f, 0.0f   );
		glVertex3f(0.4f, -0.5f, 0.0f  );
		glColor3f( 0.0f, 0.0f, 1.0f   );
		glVertex3f(0.0f, 0.5f, 1.0f   );
	glEnd();
}

void demo::drawTestRect()
{
	// immediate mode coloured rectangle... DO NOT USE IMMEDIATE MODE!!!!
	glBegin(GL_TRIANGLE_STRIP);
		glColor3f( +0.0f, +0.0f, +1.0f);
		glVertex3f(-0.5f, -0.5f, +0.0f);
		glColor3f( +1.0f, +0.0f, +1.0f);
		glVertex3f(+0.5f, -0.5f, +0.0f);
		glColor3f( +0.0f, +1.0f, +1.0f);
		glVertex3f(-0.5f, +0.5f, +0.0f);
		glColor3f( +1.0f, +1.0f, +1.0f);
		glVertex3f(+0.5f, +0.5f, +0.0f);
	glEnd();
}

void demo::drawTestAxes()
{
	// immediate mode axes; r = x, g = y, b = z... DO NOT USE IMMEDIATE MODE!!!!
	glBegin(GL_LINES);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 1.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
	glEnd();
}




//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------


// default indices for attributes
// these are what OpenGL uses for built-in attributes
// if you align your data correctly with these, you 
//	will not need to use a shader (programmed pipe)!!!
enum ATTRIB_INDEX {
	A_POSITION,
	A_BLANK_1,
	A_NORMAL,
	A_COLOR_0,
	A_COLOR_1,
	A_BLANK_2,
	A_POINT_SIZE, // POINT SIZE
	A_BLANK_3,
	A_TEX_COORD_0,

	ATTRIB_COUNT	// 16
};



// PART 1A: start using draw arrays
void demo::drawTriangleAttribs() {
	
	// ~~~ START: Prep Data
	const float colors[] = {
		+1.0f, +0.0f, +0.0f, // V1
		+0.0f, +1.0f, +0.0f, // V2
		+0.0f, +0.0f, +1.0f // V3
	};

	const float verts[] = {
		-0.4f, -0.5f, -0.5f, // V1
		+0.4f, -0.5f, +0.0f, // V2
		+0.0f, +0.5f, +1.0f // V3
	};
	// ~~~~~ END: Prep Data


	// ~~~ START: enable (pseudo-)"retained" drawing
	glEnableVertexAttribArray(A_POSITION);
	glEnableVertexAttribArray(A_COLOR_0);
	// ~~~~~ END: enable (pseudo-)"retained" drawing


	// ~~~ START: send data to GPU
	/*
		index - enum
		size - attributes per point
		type - data type of data
		normalized - want to normalize when it is sent (always false)
		stride - how far apart are the positions in the data
		pointer - the data
	*/
	glVertexAttribPointer(A_POSITION, 3, GL_FLOAT, GL_FALSE, 0, verts);
	glVertexAttribPointer(A_COLOR_0, 3, GL_FLOAT, GL_FALSE, 0, colors);
	// ~~~~~ END: send data to GPU


	// ~~~ START: draw
	glDrawArrays(GL_TRIANGLES, 0, 3);
	// glDrawArrays(GL_POINTS, 0, 3);

	// ~~~~~ END: draw


	// ~~~ START: disable retained
	glDisableVertexAttribArray(A_POSITION);
	glDisableVertexAttribArray(A_COLOR_0);
	// ~~~~~ END: disable retained

}

void demo::drawSquareAttribs() {

	// ~~~ START: Prep Data
	const float colors[] = {
		+0.0f, +0.0f, +1.0f, // C1
		+1.0f, +0.0f, +1.0f, // C2
		+0.0f, +1.0f, +1.0f, // C3
		+1.0f, +1.0f, +1.0f  // C4
	};
	const float verts[] = {
		-0.5f, -0.5f, +0.0f, // V1
		+0.5f, -0.5f, +0.0f, // V2
		-0.5f, +0.5f, +0.0f, // V3
		+0.5f, +0.5f, +0.0f  // V4
	};
	// ~~~~~ END: Prep Data


	// ~~~ START: enable (pseudo-)"retained" drawing
	glEnableVertexAttribArray(A_POSITION);
	glEnableVertexAttribArray(A_COLOR_0);
	// ~~~~~ END: enable (pseudo-)"retained" drawing


	// ~~~ START: send data to GPU
	/*
	index - enum
	size - attributes per point
	type - data type of data
	normalized - want to normalize when it is sent (always false)
	stride - how far apart are the positions in the data
	pointer - the data
	*/
	glVertexAttribPointer(A_POSITION, 3, GL_FLOAT, GL_FALSE, 0, verts);
	glVertexAttribPointer(A_COLOR_0, 3, GL_FLOAT, GL_FALSE, 0, colors);
	// ~~~~~ END: send data to GPU


	// ~~~ START: draw
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

	// ~~~~~ END: draw


	// ~~~ START: disable retained
	glDisableVertexAttribArray(A_POSITION);
	glDisableVertexAttribArray(A_COLOR_0);
	// ~~~~~ END: disable retained

}



//-----------------------------------------------------------------------------
// PART 1B: general vbo
unsigned int demo::createMultipleVBOs(unsigned int numVerts, unsigned int attribCount, const float **data, unsigned int *handlesOut)
{
	const unsigned int sizeOfFloat = sizeof(float);
	const unsigned int floatsPerAttrib = 3;

	// validate data
	if (numVerts > 0 && attribCount > 0 && attribCount <= 16 && data && handlesOut) {

		// ~~~ START: Create buffers (for-each attrib)
		glGenBuffers(attribCount, handlesOut);
		// ~~~~~ END: Create buffers

		// ~~~ START: Handle Attributes

		for (unsigned int i = 0; i < attribCount; ++i) {
			// ~~~ START: Send data to GPU
			
			// Bind the buffer
			glBindBuffer(GL_ARRAY_BUFFER, handlesOut[i]);
			
			// total bytes = size_of_data_type * num_verts * elements
			glBufferData(GL_ARRAY_BUFFER, sizeOfFloat * attribCount * numVerts, data[i], GL_STATIC_DRAW);

			// ~~~~~ END: Send data to GPU
		}

		// Unbind all buffers
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// ~~~~~ END: Handle Attributes

		return attribCount;
	}
	
	// failed
	return 0;
}

void demo::drawMultipleVBOs(unsigned int numVerts, unsigned int attribCount, unsigned int primType, const unsigned int *handles, const unsigned int *attribIndex)
{
	const unsigned int sizeOfFloat = sizeof(float);
	const unsigned int floatsPerAttrib = 3;

	// validate data
	if (numVerts > 0 && attribCount > 0 && attribCount <= 16 && handles && attribIndex) {

		// ~~~ START: Enable/Setup Attributes
		for (unsigned int i = 0; i < attribCount; ++i) {

			// ~~~ START: Enable and Setup

			// Bind attribute buffer
			glBindBuffer(GL_ARRAY_BUFFER, handles[i]);

			// enable
			glEnableVertexAttribArray(attribIndex[i]);
			
			// configure
			glVertexAttribPointer(attribIndex[i], 3, GL_FLOAT, GL_FALSE, 0, 0);

			// ~~~~~ END: Enable and Setup

		}

		// ~~~~~ END: Enable/Setup Attributes

		// ~~~ START: Draw
		glDrawArrays(primType, 0, numVerts);
		// ~~~~~ END: Draw

		// ~~~ START: Disable Attributes
		for (unsigned int i = 0; i < attribCount; ++i) {
			// disable
			glDisableVertexAttribArray(attribIndex[i]);
		}

		// Unbind Buffer
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		// ~~~~~ END: Disable Attributes

	}

}

void demo::deleteMultipleVBOs(unsigned int attribCount, unsigned int *handles)
{
	// Validate input
	if (attribCount && handles) {
		// Delete things
		glDeleteBuffers(attribCount, handles);
	}
}


