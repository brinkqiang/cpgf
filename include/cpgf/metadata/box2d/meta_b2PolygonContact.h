// Auto generated file, don't modify.

#ifndef __META_B2POLYGONCONTACT_H
#define __META_B2POLYGONCONTACT_H


#include "cpgf/gmetadefine.h"
#include "cpgf/metadata/gnamereplacer.h"
#include "cpgf/metadata/gmetadataconfig.h"
#include "cpgf/metadata/private/gmetadata_header.h"


template <typename D, typename Policy>
void buildMetaClass_B2PolygonContact(const cpgf::GMetaDataConfigFlags & config, D _d, const cpgf::GMetaDataNameReplacer * _r, const Policy & _p)
{
    (void)config; (void)_d; (void)_r; (void)_d; (void)_p;
    using namespace cpgf;
    
    _d.CPGF_MD_TEMPLATE _constructor<void * (b2Fixture *, b2Fixture *)>(_p);
    _d.CPGF_MD_TEMPLATE _method(replaceName("Create", _r), &D::ClassType::Create, _p);
    _d.CPGF_MD_TEMPLATE _method(replaceName("Destroy", _r), &D::ClassType::Destroy, _p);
    _d.CPGF_MD_TEMPLATE _method(replaceName("Evaluate", _r), &D::ClassType::Evaluate, _p);
}




#include "cpgf/metadata/private/gmetadata_footer.h"


#endif