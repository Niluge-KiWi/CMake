/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2004-2009 Kitware, Inc.
  Copyright 2004 Alexander Neundorf (neundorf@kde.org)
  Copyright 2012 Thomas Riccardi (riccardi.thomas@gmail.com)

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmExtraEDEGenerator_h
#define cmExtraEDEGenerator_h

#include "cmExternalMakefileProjectGenerator.h"

class cmLocalGenerator;
class cmMakefile;
class cmTarget;
class cmGeneratedFileStream;

/** \class cmExtraEDEGenerator
 * \brief Write EDE project files for Makefile based projects
 */
class cmExtraEDEGenerator : public cmExternalMakefileProjectGenerator
{
public:
  cmExtraEDEGenerator();

  virtual const char* GetName() const
                         { return cmExtraEDEGenerator::GetActualName();}
  static const char* GetActualName()                    { return "EDE";}
  static cmExternalMakefileProjectGenerator* New()
                                     { return new cmExtraEDEGenerator; }
  /** Get the documentation entry for this generator.  */
  virtual void GetDocumentation(cmDocumentationEntry& entry,
                                const char* fullName) const;

  virtual void Generate();
private:

  void CreateLocalGeneratorFile(cmLocalGenerator* lg);

  void CreateNewLocalGeneratorFile(cmLocalGenerator* lg,
                                   const std::string& filename);

  void CreateProjectFile(const std::vector<cmLocalGenerator*>& lgs);
  
  void CreateNewProjectFile(const std::vector<cmLocalGenerator*>& lgs,
                                const std::string& filename);
  std::string GetCBCompilerId(const cmMakefile* mf);
  int GetCBTargetType(cmTarget* target);
  std::string BuildMakeCommand(const std::string& make, const char* makefile,
                               const char* target);
  void AppendTarget(cmGeneratedFileStream& fout,
                    const char* targetName,
                    cmTarget* target,
                    const char* make,
                    const cmMakefile* makefile,
                    const char* compiler);

};

#endif
