/*@@cpgf@@*/
// Auto generated file, don't modify.

#include "meta_buildermethod.h"

using namespace cpgf;

namespace metadata {

void partial_createMetaClass_metagen(cpgf::GDefineMetaInfo metaInfo)
{
    typedef GDefineMetaNamespace MetaType;
    MetaType meta = MetaType::fromMetaClass(metaInfo.getMetaClass());
    buildMetaClass_metagen(meta);
}

void partial_createMetaClass_metagen_BuilderMethod(cpgf::GDefineMetaInfo metaInfo)
{
    typedef cpgf::GDefineMetaClass<metagen::BuilderMethod > MetaType;
    MetaType meta = MetaType::fromMetaClass(metaInfo.getMetaClass());
    buildMetaClass_metagen_BuilderMethod(meta);
}

void partial_createMetaClass_metagen(cpgf::GDefineMetaInfo metaInfo);
cpgf::GDefineMetaInfo createMetaClass_metagen()
{
    typedef GDefineMetaNamespace MetaType;
    
    GDefineMetaGlobalDangle _d = GDefineMetaGlobalDangle::dangle();
    cpgf::GDefineMetaInfo meta = _d.getMetaInfo();
    
    partial_createMetaClass_metagen(meta);
    
    return meta;
}

void partial_createMetaClass_metagen_BuilderMethod(cpgf::GDefineMetaInfo metaInfo);
cpgf::GDefineMetaInfo createMetaClass_metagen_BuilderMethod()
{
    typedef cpgf::GDefineMetaClass<metagen::BuilderMethod > MetaType;
    
    MetaType _d = MetaType::Policy<cpgf::MakePolicy<GMetaRuleDefaultConstructorAbsent > >::declare("BuilderMethod");
    cpgf::GDefineMetaInfo meta = _d.getMetaInfo();
    
    partial_createMetaClass_metagen_BuilderMethod(meta);
    
    return meta;
}

} // namespace metadata