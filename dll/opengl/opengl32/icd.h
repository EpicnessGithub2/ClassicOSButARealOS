/*
 * COPYRIGHT:            See COPYING in the top level directory
 * PROJECT:              classicOS kernel
 * FILE:                 lib/opengl32/icd.h
 * PURPOSE:              OpenGL32 lib, ICD specific definitions
 */

#pragma once

#define OPENGL_VERSION_110_ENTRIES  336

struct __GLdispatchTableRec
{
   void (GLAPIENTRY * NewList)(GLuint, GLenum);
   void (GLAPIENTRY * EndList)(void);
   void (GLAPIENTRY * CallList)(GLuint);
   void (GLAPIENTRY * CallLists)(GLsizei, GLenum, const GLvoid *);
   void (GLAPIENTRY * DeleteLists)(GLuint, GLsizei);
   GLuint (GLAPIENTRY * GenLists)(GLsizei);
   void (GLAPIENTRY * ListBase)(GLuint);
   void (GLAPIENTRY * Begin)(GLenum);
   void (GLAPIENTRY * Bitmap)(GLsizei, GLsizei, GLfloat, GLfloat, GLfloat, GLfloat, const GLubyte *);
   void (GLAPIENTRY * Color3b)(GLbyte, GLbyte, GLbyte);
   void (GLAPIENTRY * Color3bv)(const GLbyte *);
   void (GLAPIENTRY * Color3d)(GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * Color3dv)(const GLdouble *);
   void (GLAPIENTRY * Color3f)(GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * Color3fv)(const GLfloat *);
   void (GLAPIENTRY * Color3i)(GLint, GLint, GLint);
   void (GLAPIENTRY * Color3iv)(const GLint *);
   void (GLAPIENTRY * Color3s)(GLshort, GLshort, GLshort);
   void (GLAPIENTRY * Color3sv)(const GLshort *);
   void (GLAPIENTRY * Color3ub)(GLubyte, GLubyte, GLubyte);
   void (GLAPIENTRY * Color3ubv)(const GLubyte *);
   void (GLAPIENTRY * Color3ui)(GLuint, GLuint, GLuint);
   void (GLAPIENTRY * Color3uiv)(const GLuint *);
   void (GLAPIENTRY * Color3us)(GLushort, GLushort, GLushort);
   void (GLAPIENTRY * Color3usv)(const GLushort *);
   void (GLAPIENTRY * Color4b)(GLbyte, GLbyte, GLbyte, GLbyte);
   void (GLAPIENTRY * Color4bv)(const GLbyte *);
   void (GLAPIENTRY * Color4d)(GLdouble, GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * Color4dv)(const GLdouble *);
   void (GLAPIENTRY * Color4f)(GLfloat, GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * Color4fv)(const GLfloat *);
   void (GLAPIENTRY * Color4i)(GLint, GLint, GLint, GLint);
   void (GLAPIENTRY * Color4iv)(const GLint *);
   void (GLAPIENTRY * Color4s)(GLshort, GLshort, GLshort, GLshort);
   void (GLAPIENTRY * Color4sv)(const GLshort *);
   void (GLAPIENTRY * Color4ub)(GLubyte, GLubyte, GLubyte, GLubyte);
   void (GLAPIENTRY * Color4ubv)(const GLubyte *);
   void (GLAPIENTRY * Color4ui)(GLuint, GLuint, GLuint, GLuint);
   void (GLAPIENTRY * Color4uiv)(const GLuint *);
   void (GLAPIENTRY * Color4us)(GLushort, GLushort, GLushort, GLushort);
   void (GLAPIENTRY * Color4usv)(const GLushort *);
   void (GLAPIENTRY * EdgeFlag)(GLboolean);
   void (GLAPIENTRY * EdgeFlagv)(const GLboolean *);
   void (GLAPIENTRY * End)(void);
   void (GLAPIENTRY * Indexd)(GLdouble);
   void (GLAPIENTRY * Indexdv)(const GLdouble *);
   void (GLAPIENTRY * Indexf)(GLfloat);
   void (GLAPIENTRY * Indexfv)(const GLfloat *);
   void (GLAPIENTRY * Indexi)(GLint);
   void (GLAPIENTRY * Indexiv)(const GLint *);
   void (GLAPIENTRY * Indexs)(GLshort);
   void (GLAPIENTRY * Indexsv)(const GLshort *);
   void (GLAPIENTRY * Normal3b)(GLbyte, GLbyte, GLbyte);
   void (GLAPIENTRY * Normal3bv)(const GLbyte *);
   void (GLAPIENTRY * Normal3d)(GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * Normal3dv)(const GLdouble *);
   void (GLAPIENTRY * Normal3f)(GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * Normal3fv)(const GLfloat *);
   void (GLAPIENTRY * Normal3i)(GLint, GLint, GLint);
   void (GLAPIENTRY * Normal3iv)(const GLint *);
   void (GLAPIENTRY * Normal3s)(GLshort, GLshort, GLshort);
   void (GLAPIENTRY * Normal3sv)(const GLshort *);
   void (GLAPIENTRY * RasterPos2d)(GLdouble, GLdouble);
   void (GLAPIENTRY * RasterPos2dv)(const GLdouble *);
   void (GLAPIENTRY * RasterPos2f)(GLfloat, GLfloat);
   void (GLAPIENTRY * RasterPos2fv)(const GLfloat *);
   void (GLAPIENTRY * RasterPos2i)(GLint, GLint);
   void (GLAPIENTRY * RasterPos2iv)(const GLint *);
   void (GLAPIENTRY * RasterPos2s)(GLshort, GLshort);
   void (GLAPIENTRY * RasterPos2sv)(const GLshort *);
   void (GLAPIENTRY * RasterPos3d)(GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * RasterPos3dv)(const GLdouble *);
   void (GLAPIENTRY * RasterPos3f)(GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * RasterPos3fv)(const GLfloat *);
   void (GLAPIENTRY * RasterPos3i)(GLint, GLint, GLint);
   void (GLAPIENTRY * RasterPos3iv)(const GLint *);
   void (GLAPIENTRY * RasterPos3s)(GLshort, GLshort, GLshort);
   void (GLAPIENTRY * RasterPos3sv)(const GLshort *);
   void (GLAPIENTRY * RasterPos4d)(GLdouble, GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * RasterPos4dv)(const GLdouble *);
   void (GLAPIENTRY * RasterPos4f)(GLfloat, GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * RasterPos4fv)(const GLfloat *);
   void (GLAPIENTRY * RasterPos4i)(GLint, GLint, GLint, GLint);
   void (GLAPIENTRY * RasterPos4iv)(const GLint *);
   void (GLAPIENTRY * RasterPos4s)(GLshort, GLshort, GLshort, GLshort);
   void (GLAPIENTRY * RasterPos4sv)(const GLshort *);
   void (GLAPIENTRY * Rectd)(GLdouble, GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * Rectdv)(const GLdouble *, const GLdouble *);
   void (GLAPIENTRY * Rectf)(GLfloat, GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * Rectfv)(const GLfloat *, const GLfloat *);
   void (GLAPIENTRY * Recti)(GLint, GLint, GLint, GLint);
   void (GLAPIENTRY * Rectiv)(const GLint *, const GLint *);
   void (GLAPIENTRY * Rects)(GLshort, GLshort, GLshort, GLshort);
   void (GLAPIENTRY * Rectsv)(const GLshort *, const GLshort *);
   void (GLAPIENTRY * TexCoord1d)(GLdouble);
   void (GLAPIENTRY * TexCoord1dv)(const GLdouble *);
   void (GLAPIENTRY * TexCoord1f)(GLfloat);
   void (GLAPIENTRY * TexCoord1fv)(const GLfloat *);
   void (GLAPIENTRY * TexCoord1i)(GLint);
   void (GLAPIENTRY * TexCoord1iv)(const GLint *);
   void (GLAPIENTRY * TexCoord1s)(GLshort);
   void (GLAPIENTRY * TexCoord1sv)(const GLshort *);
   void (GLAPIENTRY * TexCoord2d)(GLdouble, GLdouble);
   void (GLAPIENTRY * TexCoord2dv)(const GLdouble *);
   void (GLAPIENTRY * TexCoord2f)(GLfloat, GLfloat);
   void (GLAPIENTRY * TexCoord2fv)(const GLfloat *);
   void (GLAPIENTRY * TexCoord2i)(GLint, GLint);
   void (GLAPIENTRY * TexCoord2iv)(const GLint *);
   void (GLAPIENTRY * TexCoord2s)(GLshort, GLshort);
   void (GLAPIENTRY * TexCoord2sv)(const GLshort *);
   void (GLAPIENTRY * TexCoord3d)(GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * TexCoord3dv)(const GLdouble *);
   void (GLAPIENTRY * TexCoord3f)(GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * TexCoord3fv)(const GLfloat *);
   void (GLAPIENTRY * TexCoord3i)(GLint, GLint, GLint);
   void (GLAPIENTRY * TexCoord3iv)(const GLint *);
   void (GLAPIENTRY * TexCoord3s)(GLshort, GLshort, GLshort);
   void (GLAPIENTRY * TexCoord3sv)(const GLshort *);
   void (GLAPIENTRY * TexCoord4d)(GLdouble, GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * TexCoord4dv)(const GLdouble *);
   void (GLAPIENTRY * TexCoord4f)(GLfloat, GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * TexCoord4fv)(const GLfloat *);
   void (GLAPIENTRY * TexCoord4i)(GLint, GLint, GLint, GLint);
   void (GLAPIENTRY * TexCoord4iv)(const GLint *);
   void (GLAPIENTRY * TexCoord4s)(GLshort, GLshort, GLshort, GLshort);
   void (GLAPIENTRY * TexCoord4sv)(const GLshort *);
   void (GLAPIENTRY * Vertex2d)(GLdouble, GLdouble);
   void (GLAPIENTRY * Vertex2dv)(const GLdouble *);
   void (GLAPIENTRY * Vertex2f)(GLfloat, GLfloat);
   void (GLAPIENTRY * Vertex2fv)(const GLfloat *);
   void (GLAPIENTRY * Vertex2i)(GLint, GLint);
   void (GLAPIENTRY * Vertex2iv)(const GLint *);
   void (GLAPIENTRY * Vertex2s)(GLshort, GLshort);
   void (GLAPIENTRY * Vertex2sv)(const GLshort *);
   void (GLAPIENTRY * Vertex3d)(GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * Vertex3dv)(const GLdouble *);
   void (GLAPIENTRY * Vertex3f)(GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * Vertex3fv)(const GLfloat *);
   void (GLAPIENTRY * Vertex3i)(GLint, GLint, GLint);
   void (GLAPIENTRY * Vertex3iv)(const GLint *);
   void (GLAPIENTRY * Vertex3s)(GLshort, GLshort, GLshort);
   void (GLAPIENTRY * Vertex3sv)(const GLshort *);
   void (GLAPIENTRY * Vertex4d)(GLdouble, GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * Vertex4dv)(const GLdouble *);
   void (GLAPIENTRY * Vertex4f)(GLfloat, GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * Vertex4fv)(const GLfloat *);
   void (GLAPIENTRY * Vertex4i)(GLint, GLint, GLint, GLint);
   void (GLAPIENTRY * Vertex4iv)(const GLint *);
   void (GLAPIENTRY * Vertex4s)(GLshort, GLshort, GLshort, GLshort);
   void (GLAPIENTRY * Vertex4sv)(const GLshort *);
   void (GLAPIENTRY * ClipPlane)(GLenum, const GLdouble *);
   void (GLAPIENTRY * ColorMaterial)(GLenum, GLenum);
   void (GLAPIENTRY * CullFace)(GLenum);
   void (GLAPIENTRY * Fogf)(GLenum, GLfloat);
   void (GLAPIENTRY * Fogfv)(GLenum, const GLfloat *);
   void (GLAPIENTRY * Fogi)(GLenum, GLint);
   void (GLAPIENTRY * Fogiv)(GLenum, const GLint *);
   void (GLAPIENTRY * FrontFace)(GLenum);
   void (GLAPIENTRY * Hint)(GLenum, GLenum);
   void (GLAPIENTRY * Lightf)(GLenum, GLenum, GLfloat);
   void (GLAPIENTRY * Lightfv)(GLenum, GLenum, const GLfloat *);
   void (GLAPIENTRY * Lighti)(GLenum, GLenum, GLint);
   void (GLAPIENTRY * Lightiv)(GLenum, GLenum, const GLint *);
   void (GLAPIENTRY * LightModelf)(GLenum, GLfloat);
   void (GLAPIENTRY * LightModelfv)(GLenum, const GLfloat *);
   void (GLAPIENTRY * LightModeli)(GLenum, GLint);
   void (GLAPIENTRY * LightModeliv)(GLenum, const GLint *);
   void (GLAPIENTRY * LineStipple)(GLint, GLushort);
   void (GLAPIENTRY * LineWidth)(GLfloat);
   void (GLAPIENTRY * Materialf)(GLenum, GLenum, GLfloat);
   void (GLAPIENTRY * Materialfv)(GLenum, GLenum, const GLfloat *);
   void (GLAPIENTRY * Materiali)(GLenum, GLenum, GLint);
   void (GLAPIENTRY * Materialiv)(GLenum, GLenum, const GLint *);
   void (GLAPIENTRY * PointSize)(GLfloat);
   void (GLAPIENTRY * PolygonMode)(GLenum, GLenum);
   void (GLAPIENTRY * PolygonStipple)(const GLubyte *);
   void (GLAPIENTRY * Scissor)(GLint, GLint, GLsizei, GLsizei);
   void (GLAPIENTRY * ShadeModel)(GLenum);
   void (GLAPIENTRY * TexParameterf)(GLenum, GLenum, GLfloat);
   void (GLAPIENTRY * TexParameterfv)(GLenum, GLenum, const GLfloat *);
   void (GLAPIENTRY * TexParameteri)(GLenum, GLenum, GLint);
   void (GLAPIENTRY * TexParameteriv)(GLenum, GLenum, const GLint *);
   void (GLAPIENTRY * TexImage1D)(GLenum, GLint, GLint, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
   void (GLAPIENTRY * TexImage2D)(GLenum, GLint, GLint, GLsizei, GLsizei, GLint, GLenum, GLenum, const GLvoid *);
   void (GLAPIENTRY * TexEnvf)(GLenum, GLenum, GLfloat);
   void (GLAPIENTRY * TexEnvfv)(GLenum, GLenum, const GLfloat *);
   void (GLAPIENTRY * TexEnvi)(GLenum, GLenum, GLint);
   void (GLAPIENTRY * TexEnviv)(GLenum, GLenum, const GLint *);
   void (GLAPIENTRY * TexGend)(GLenum, GLenum, GLdouble);
   void (GLAPIENTRY * TexGendv)(GLenum, GLenum, const GLdouble *);
   void (GLAPIENTRY * TexGenf)(GLenum, GLenum, GLfloat);
   void (GLAPIENTRY * TexGenfv)(GLenum, GLenum, const GLfloat *);
   void (GLAPIENTRY * TexGeni)(GLenum, GLenum, GLint);
   void (GLAPIENTRY * TexGeniv)(GLenum, GLenum, const GLint *);
   void (GLAPIENTRY * FeedbackBuffer)(GLsizei, GLenum, GLfloat *);
   void (GLAPIENTRY * SelectBuffer)(GLsizei, GLuint *);
   GLint (GLAPIENTRY * RenderMode)(GLenum);
   void (GLAPIENTRY * InitNames)(void);
   void (GLAPIENTRY * LoadName)(GLuint);
   void (GLAPIENTRY * PassThrough)(GLfloat);
   void (GLAPIENTRY * PopName)(void);
   void (GLAPIENTRY * PushName)(GLuint);
   void (GLAPIENTRY * DrawBuffer)(GLenum);
   void (GLAPIENTRY * Clear)(GLbitfield);
   void (GLAPIENTRY * ClearAccum)(GLfloat, GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * ClearIndex)(GLfloat);
   void (GLAPIENTRY * ClearColor)(GLclampf, GLclampf, GLclampf, GLclampf);
   void (GLAPIENTRY * ClearStencil)(GLint);
   void (GLAPIENTRY * ClearDepth)(GLclampd);
   void (GLAPIENTRY * StencilMask)(GLuint);
   void (GLAPIENTRY * ColorMask)(GLboolean, GLboolean, GLboolean, GLboolean);
   void (GLAPIENTRY * DepthMask)(GLboolean);
   void (GLAPIENTRY * IndexMask)(GLuint);
   void (GLAPIENTRY * Accum)(GLenum, GLfloat);
   void (GLAPIENTRY * Disable)(GLenum);
   void (GLAPIENTRY * Enable)(GLenum);
   void (GLAPIENTRY * Finish)(void);
   void (GLAPIENTRY * Flush)(void);
   void (GLAPIENTRY * PopAttrib)(void);
   void (GLAPIENTRY * PushAttrib)(GLbitfield);
   void (GLAPIENTRY * Map1d)(GLenum, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
   void (GLAPIENTRY * Map1f)(GLenum, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
   void (GLAPIENTRY * Map2d)(GLenum, GLdouble, GLdouble, GLint, GLint, GLdouble, GLdouble, GLint, GLint, const GLdouble *);
   void (GLAPIENTRY * Map2f)(GLenum, GLfloat, GLfloat, GLint, GLint, GLfloat, GLfloat, GLint, GLint, const GLfloat *);
   void (GLAPIENTRY * MapGrid1d)(GLint, GLdouble, GLdouble);
   void (GLAPIENTRY * MapGrid1f)(GLint, GLfloat, GLfloat);
   void (GLAPIENTRY * MapGrid2d)(GLint, GLdouble, GLdouble, GLint, GLdouble, GLdouble);
   void (GLAPIENTRY * MapGrid2f)(GLint, GLfloat, GLfloat, GLint, GLfloat, GLfloat);
   void (GLAPIENTRY * EvalCoord1d)(GLdouble);
   void (GLAPIENTRY * EvalCoord1dv)(const GLdouble *);
   void (GLAPIENTRY * EvalCoord1f)(GLfloat);
   void (GLAPIENTRY * EvalCoord1fv)(const GLfloat *);
   void (GLAPIENTRY * EvalCoord2d)(GLdouble, GLdouble);
   void (GLAPIENTRY * EvalCoord2dv)(const GLdouble *);
   void (GLAPIENTRY * EvalCoord2f)(GLfloat, GLfloat);
   void (GLAPIENTRY * EvalCoord2fv)(const GLfloat *);
   void (GLAPIENTRY * EvalMesh1)(GLenum, GLint, GLint);
   void (GLAPIENTRY * EvalPoint1)(GLint);
   void (GLAPIENTRY * EvalMesh2)(GLenum, GLint, GLint, GLint, GLint);
   void (GLAPIENTRY * EvalPoint2)(GLint, GLint);
   void (GLAPIENTRY * AlphaFunc)(GLenum, GLclampf);
   void (GLAPIENTRY * BlendFunc)(GLenum, GLenum);
   void (GLAPIENTRY * LogicOp)(GLenum);
   void (GLAPIENTRY * StencilFunc)(GLenum, GLint, GLuint);
   void (GLAPIENTRY * StencilOp)(GLenum, GLenum, GLenum);
   void (GLAPIENTRY * DepthFunc)(GLenum);
   void (GLAPIENTRY * PixelZoom)(GLfloat, GLfloat);
   void (GLAPIENTRY * PixelTransferf)(GLenum, GLfloat);
   void (GLAPIENTRY * PixelTransferi)(GLenum, GLint);
   void (GLAPIENTRY * PixelStoref)(GLenum, GLfloat);
   void (GLAPIENTRY * PixelStorei)(GLenum, GLint);
   void (GLAPIENTRY * PixelMapfv)(GLenum, GLint, const GLfloat *);
   void (GLAPIENTRY * PixelMapuiv)(GLenum, GLint, const GLuint *);
   void (GLAPIENTRY * PixelMapusv)(GLenum, GLint, const GLushort *);
   void (GLAPIENTRY * ReadBuffer)(GLenum);
   void (GLAPIENTRY * CopyPixels)(GLint, GLint, GLsizei, GLsizei, GLenum);
   void (GLAPIENTRY * ReadPixels)(GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, GLvoid *);
   void (GLAPIENTRY * DrawPixels)(GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
   void (GLAPIENTRY * GetBooleanv)(GLenum, GLboolean *);
   void (GLAPIENTRY * GetClipPlane)(GLenum, GLdouble *);
   void (GLAPIENTRY * GetDoublev)(GLenum, GLdouble *);
   GLenum (GLAPIENTRY * GetError)(void);
   void (GLAPIENTRY * GetFloatv)(GLenum, GLfloat *);
   void (GLAPIENTRY * GetIntegerv)(GLenum, GLint *);
   void (GLAPIENTRY * GetLightfv)(GLenum, GLenum, GLfloat *);
   void (GLAPIENTRY * GetLightiv)(GLenum, GLenum, GLint *);
   void (GLAPIENTRY * GetMapdv)(GLenum, GLenum, GLdouble *);
   void (GLAPIENTRY * GetMapfv)(GLenum, GLenum, GLfloat *);
   void (GLAPIENTRY * GetMapiv)(GLenum, GLenum, GLint *);
   void (GLAPIENTRY * GetMaterialfv)(GLenum, GLenum, GLfloat *);
   void (GLAPIENTRY * GetMaterialiv)(GLenum, GLenum, GLint *);
   void (GLAPIENTRY * GetPixelMapfv)(GLenum, GLfloat *);
   void (GLAPIENTRY * GetPixelMapuiv)(GLenum, GLuint *);
   void (GLAPIENTRY * GetPixelMapusv)(GLenum, GLushort *);
   void (GLAPIENTRY * GetPolygonStipple)(GLubyte *);
   const GLubyte * (GLAPIENTRY * GetString)(GLenum);
   void (GLAPIENTRY * GetTexEnvfv)(GLenum, GLenum, GLfloat *);
   void (GLAPIENTRY * GetTexEnviv)(GLenum, GLenum, GLint *);
   void (GLAPIENTRY * GetTexGendv)(GLenum, GLenum, GLdouble *);
   void (GLAPIENTRY * GetTexGenfv)(GLenum, GLenum, GLfloat *);
   void (GLAPIENTRY * GetTexGeniv)(GLenum, GLenum, GLint *);
   void (GLAPIENTRY * GetTexImage)(GLenum, GLint, GLenum, GLenum, GLvoid *);
   void (GLAPIENTRY * GetTexParameterfv)(GLenum, GLenum, GLfloat *);
   void (GLAPIENTRY * GetTexParameteriv)(GLenum, GLenum, GLint *);
   void (GLAPIENTRY * GetTexLevelParameterfv)(GLenum, GLint, GLenum, GLfloat *);
   void (GLAPIENTRY * GetTexLevelParameteriv)(GLenum, GLint, GLenum, GLint *);
   GLboolean (GLAPIENTRY * IsEnabled)(GLenum);
   GLboolean (GLAPIENTRY * IsList)(GLuint);
   void (GLAPIENTRY * DepthRange)(GLclampd, GLclampd);
   void (GLAPIENTRY * Frustum)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * LoadIdentity)(void);
   void (GLAPIENTRY * LoadMatrixf)(const GLfloat *);
   void (GLAPIENTRY * LoadMatrixd)(const GLdouble *);
   void (GLAPIENTRY * MatrixMode)(GLenum);
   void (GLAPIENTRY * MultMatrixf)(const GLfloat *);
   void (GLAPIENTRY * MultMatrixd)(const GLdouble *);
   void (GLAPIENTRY * Ortho)(GLdouble, GLdouble, GLdouble, GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * PopMatrix)(void);
   void (GLAPIENTRY * PushMatrix)(void);
   void (GLAPIENTRY * Rotated)(GLdouble, GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * Rotatef)(GLfloat, GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * Scaled)(GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * Scalef)(GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * Translated)(GLdouble, GLdouble, GLdouble);
   void (GLAPIENTRY * Translatef)(GLfloat, GLfloat, GLfloat);
   void (GLAPIENTRY * Viewport)(GLint, GLint, GLsizei, GLsizei);
   void (GLAPIENTRY * ArrayElement)(GLint);
   void (GLAPIENTRY * BindTexture)(GLenum, GLuint);
   void (GLAPIENTRY * ColorPointer)(GLint, GLenum, GLsizei, const GLvoid *);
   void (GLAPIENTRY * DisableClientState)(GLenum);
   void (GLAPIENTRY * DrawArrays)(GLenum, GLint, GLsizei);
   void (GLAPIENTRY * DrawElements)(GLenum, GLsizei, GLenum, const GLvoid *);
   void (GLAPIENTRY * EdgeFlagPointer)(GLsizei, const GLvoid *);
   void (GLAPIENTRY * EnableClientState)(GLenum);
   void (GLAPIENTRY * IndexPointer)(GLenum, GLsizei, const GLvoid *);
   void (GLAPIENTRY * Indexub)(GLubyte);
   void (GLAPIENTRY * Indexubv)(const GLubyte *);
   void (GLAPIENTRY * InterleavedArrays)(GLenum, GLsizei, const GLvoid *);
   void (GLAPIENTRY * NormalPointer)(GLenum, GLsizei, const GLvoid *);
   void (GLAPIENTRY * PolygonOffset)(GLfloat, GLfloat);
   void (GLAPIENTRY * TexCoordPointer)(GLint, GLenum, GLsizei, const GLvoid *);
   void (GLAPIENTRY * VertexPointer)(GLint, GLenum, GLsizei, const GLvoid *);
   GLboolean (GLAPIENTRY * AreTexturesResident)(GLsizei, const GLuint *, GLboolean *);
   void (GLAPIENTRY * CopyTexImage1D)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLint);
   void (GLAPIENTRY * CopyTexImage2D)(GLenum, GLint, GLenum, GLint, GLint, GLsizei, GLsizei, GLint);
   void (GLAPIENTRY * CopyTexSubImage1D)(GLenum, GLint, GLint, GLint, GLint, GLsizei);
   void (GLAPIENTRY * CopyTexSubImage2D)(GLenum, GLint, GLint, GLint, GLint, GLint, GLsizei, GLsizei);
   void (GLAPIENTRY * DeleteTextures)(GLsizei, const GLuint *);
   void (GLAPIENTRY * GenTextures)(GLsizei, GLuint *);
   void (GLAPIENTRY * GetPointerv)(GLenum, GLvoid **);
   GLboolean (GLAPIENTRY * IsTexture)(GLuint);
   void (GLAPIENTRY * PrioritizeTextures)(GLsizei, const GLuint *, const GLclampf *);
   void (GLAPIENTRY * TexSubImage1D)(GLenum, GLint, GLint, GLsizei, GLenum, GLenum, const GLvoid *);
   void (GLAPIENTRY * TexSubImage2D)(GLenum, GLint, GLint, GLint, GLsizei, GLsizei, GLenum, GLenum, const GLvoid *);
   void (GLAPIENTRY * PopClientAttrib)(void);
   void (GLAPIENTRY * PushClientAttrib)(GLbitfield);
};

typedef struct __GLdispatchTableRec GLDISPATCHTABLE;

typedef struct _GLCLTPROCTABLE
{
   int cEntries;
   GLDISPATCHTABLE glDispatchTable;
} GLCLTPROCTABLE, * PGLCLTPROCTABLE;

typedef VOID (APIENTRY * PFN_SETPROCTABLE)(const GLCLTPROCTABLE*);

/* This doesn't seem to be anywhere in ddk or psdk */
DECLARE_HANDLE(DHGLRC);

struct ICD_Data
{
    /* The Name returned with OPENGL_GETINFO escape code */
    WCHAR DriverName[256];
    /* The DLL handle */
    HMODULE hModule;

    /* The ICD DLL exports */
    BOOL      (WINAPI *DrvCopyContext)( DHGLRC, DHGLRC, UINT );
    DHGLRC    (WINAPI *DrvCreateContext)( HDC );
    DHGLRC    (WINAPI *DrvCreateLayerContext)( HDC, int );
    BOOL      (WINAPI *DrvDeleteContext)( DHGLRC );
    BOOL      (WINAPI *DrvDescribeLayerPlane)( HDC, int, int, UINT, LPLAYERPLANEDESCRIPTOR );
    int       (WINAPI *DrvDescribePixelFormat)( IN HDC, IN int, IN UINT, OUT LPPIXELFORMATDESCRIPTOR );
    int       (WINAPI *DrvGetLayerPaletteEntries)( HDC, int, int, int, COLORREF * );
    PROC      (WINAPI *DrvGetProcAddress)( LPCSTR lpProcName );
    void      (WINAPI *DrvReleaseContext)( DHGLRC hglrc ); /* maybe returns BOOL? */
    BOOL      (WINAPI *DrvRealizeLayerPalette)( HDC, int, BOOL );
    const GLCLTPROCTABLE* (WINAPI *DrvSetContext)( HDC hdc, DHGLRC hglrc, PFN_SETPROCTABLE callback );
    int       (WINAPI *DrvSetLayerPaletteEntries)( HDC, int, int, int, CONST COLORREF * );
    BOOL      (WINAPI *DrvSetPixelFormat)( IN HDC, IN int);
    BOOL      (WINAPI *DrvShareLists)( DHGLRC, DHGLRC );
    BOOL      (WINAPI *DrvSwapBuffers)( HDC );
    BOOL      (WINAPI *DrvSwapLayerBuffers)( HDC, UINT );

    /* Make this a linked list */
    struct ICD_Data* next;
};

struct ICD_Data* IntGetIcdData(HDC hdc);

