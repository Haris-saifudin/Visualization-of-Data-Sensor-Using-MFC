// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "C:\\Windows\\SysWow64\\MSCOMM32.OCX" no_namespace
// CDMSCommEvents wrapper class

class CDMSCommEvents : public COleDispatchDriver
{
public:
	CDMSCommEvents(){} // Calls COleDispatchDriver default constructor
	CDMSCommEvents(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CDMSCommEvents(const CDMSCommEvents& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// DMSCommEvents methods
public:
	void OnComm()
	{
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
	}

	// DMSCommEvents properties
public:

};
