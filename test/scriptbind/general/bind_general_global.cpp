#include "../testscriptbind.h"
#include "../testscriptbindmetadata2.h"


namespace {

template <typename T>
void doTestGlobal(T * binding, TestScriptContext * context)
{
	GScopedInterface<IMetaClass> metaClass(context->getService()->findClassByName(REG_NAME_TestData));
	GCHECK(metaClass);
	
	GScopedPointer<TestData> dataLib(new TestData);
	GScopedPointer<TestData> dataApi(new TestData);
	dataLib->x = 10;
	dataLib->name = "abc";
	dataApi->x = 10;
	dataApi->name = "abc";

	binding->bindObject("data", dataLib.get(), metaClass.get(), false);
	
	QASSERT(data.x == 10)
	QASSERT(data.name == "abc")
	QDO(data.x = data.x + 1)
	
	GEQUAL(dataLib->x, 11);
	
	binding->nullifyValue("data");
	
	if(context->isLua()) {
		QASSERT(data == nil)
	}
	if(context->isV8() || context->isSpiderMonkey()) {
		QASSERT(data == null)
	}
	if(context->isPython()) {
		QASSERT(data == None)
	}
}

void testGlobal(TestScriptContext * context)
{
	IScriptObject * bindingApi = context->getBindingApi();
	GScriptObject * bindingLib = context->getBindingLib();

	if(bindingLib) {
		doTestGlobal(bindingLib, context);
	}
	
	if(bindingApi) {
		doTestGlobal(bindingApi, context);
	}
}

#define CASE testGlobal
#include "../bind_testcase.h"


void testStaticMember(TestScriptContext * context)
{
	TestObject::staticValue = 0;
	GCHECK(TestObject::staticValue == 0);

	QDO(TestObject.staticValue = 10)
	GCHECK(TestObject::staticValue == 10);
	
	QDO(a = TestObject.incStaticValue())
	QASSERT(a == 11);
	GCHECK(TestObject::staticValue == 11);
}

#define CASE testStaticMember
#include "../bind_testcase.h"




}
