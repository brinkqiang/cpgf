#ifndef __CPPITEM_H
#define __CPPITEM_H

#include "cpgf/gflags.h"

#include <string>
#include <ostream>

namespace clang { class Decl; class ASTContext; }


enum ItemVisibility
{
	ivPublic, ivProtected, ivPrivate
};

enum ItemCategory
{
	icFile = 0, icNamespace, icClass, icEnum,
	icConstructor, icDestructor,
	icField, icMethod, icOperator,
	icCount
};

enum ItemTextOption
{
	itoWithType = 1 << 0,
	itoWithName = 1 << 1,
	itoWithDefaultValue = 1 << 2
};

typedef cpgf::GFlags<ItemTextOption> ItemTextOptionFlags;

extern const char * const ItemNames[icCount];


class CppContainer;
class CppContext;
class Config;

class CppItem
{
private:
	enum ItemFlags {
		ifInMainFile = 1 << 0
	};
	
protected:
	explicit CppItem(const clang::Decl * decl);

public:
	virtual ~CppItem();

	virtual ItemCategory getCategory() const = 0;

	virtual void dump(std::ostream & os, int level = 0) const;

	const CppContainer * getParent() const { return this->parent; }
	const CppContainer * getNamedParent() const; // return non-anonymous parent

	bool isInMainFile() const { return this->flags.has(ifInMainFile); }
	
	ItemVisibility getVisibility() const;

	bool isFile() const { return this->getCategory() == icFile; }
	bool isNamespace() const { return this->getCategory() == icNamespace; }
	bool isClass() const { return this->getCategory() == icClass; }
	bool isConstructor() const { return this->getCategory() == icConstructor; }
	bool isDestructor() const { return this->getCategory() == icDestructor; }
	bool isEnum() const { return this->getCategory() == icEnum; }
	bool isField() const { return this->getCategory() == icField; }
	bool isMethod() const { return this->getCategory() == icMethod; }
	bool isOperator() const { return this->getCategory() == icOperator; }
	bool isContainer() const { return this->isFile() || this->isNamespace() || this->isClass(); }
	
protected:
	const clang::Decl * getDecl() const { return this->declaration; }
	const clang::ASTContext * getASTContext() const;
	
	void setCppContext(const CppContext * cppContext) { this->cppContext = cppContext; }	
	const CppContext * getCppContext() const { return this->cppContext; }
	
	const Config * getConfig() const;
	
	void setParent(CppContainer * parent) { this->parent = parent; }

	void setInMainFile(bool inMainFile) { this->flags.setByBool(ifInMainFile, inMainFile); }
	
	void dumpIndent(std::ostream & os, int level) const;
	
private:
	const clang::Decl * declaration;
	ItemVisibility visibility;
	const CppContainer * parent; // file, namespace or class
	const CppContext * cppContext;
	cpgf::GFlags<ItemFlags> flags;

private:
	friend class CppContext;
	friend class CppContainer;
	friend class ClangParserImplement;
};

class CppNamedItem : public CppItem
{
private:
	typedef CppItem super;

public:
	const std::string & getName() const;
	const std::string & getQualifiedName() const;
	const std::string & getQualifiedNameWithoutNamespace() const;

	const std::string & getOutputName() const;

protected:
	explicit CppNamedItem(const clang::Decl * decl);
	
private:
	void checkLoadNames() const;

private:
	mutable std::string name;
	mutable std::string qualifiedName;
	mutable std::string qualifiedNameWithoutNamespace;
};


#endif
