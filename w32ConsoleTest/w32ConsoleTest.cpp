// w32ConsoleTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TPConnectorDll.h"
#include <Windows.h>
#include <iostream>

using namespace std;



int _tmain(int argc, _TCHAR* argv[])
{
	int ret=0;
	//const string Dllfile = "TPConnectorDll.dll";
	LPCWSTR DLL_PATH = L"ExLinkTPConnectorDll.dll";

#ifdef _DEBUG
	//const std::string endPointURL		= "https://developers.todopago.com.ar/services/t/1.1//services/Authorize";
	const std::string endPointURL		= "https://developers.todopago.com.ar/services/t/1.1//services/";
	const std::string strAthorization	= "PRISMA f3d8b72c94ab4a06be2ef7c95490f7d3";
#else
	const std::string endPointURL		= "https://developers.todopago.com.ar/services/t/1.1//services/";
	const std::string strAthorization	= "PRISMA f3d8b72c94ab4a06be2ef7c95490f7d3";
#endif
	map<string, string>::iterator it;
	map<string, string>RParams;
	map<string, string>PayLParams;
	map<string, string>output;

	map<string, string>GAAnswerInp;
	map<string, string>GAAnswerOut;

	map<string, string>GBiIDInp;
	map<string, string>GBiIDIOut;


	RParams[SECURITY]	= "912EC803B2CE49E4A541068D495AB570";
	RParams[SESSION]	= "ABCDEF-1234-12221-FDE1-00000200";
	RParams[MERCHANT]	= "2153";
	RParams[URL_OK]		= "http://google.com";
	RParams[URL_ERROR]	= "http://www.coco.com";
	RParams[ENCODING_METHOD] = "XML";
	

	PayLParams[EMAILCLIENTE]	= "client_email@dominio.com";
	PayLParams[AMOUNT]			= "55";
	PayLParams[CURRENCYCODE]	= "032";
	PayLParams[OPERATIONID]		= "01";
	PayLParams[PAYL_MERCHANT]	= "2153";

	PayLParams[CSBTCITY]		= "Villa General Belgrano"; //MANDATORIO.
	PayLParams[CSSTCITY	]		= "Villa General Belgrano"; //MANDATORIO.
           
	PayLParams[CSBTCOUNTRY]		= "AR";//MANDATORIO. Código ISO.
	PayLParams[CSSTCOUNTRY]		= "AR";//MANDATORIO. Código ISO.
             
	PayLParams[CSBTEMAIL]		= "todopago@hotmail.com"; //MANDATORIO.
	PayLParams[CSSTEMAIL]		= "todopago@hotmail.com"; //MANDATORIO.
             
	PayLParams[CSBTFIRSTNAME]	= "Juan";//MANDATORIO.      
	PayLParams[CSSTFIRSTNAME]	= "Juan";//MANDATORIO.      
             
	PayLParams[CSBTLASTNAME]	= "Perez";//MANDATORIO.
	PayLParams[CSSTLASTNAME]	= "Perez";//MANDATORIO.
             
	PayLParams[CSBTPHONENUMBER]	= "541160913988";//MANDATORIO.     
	PayLParams[CSSTPHONENUMBER]	= "541160913988";//MANDATORIO.     
             
	PayLParams[CSBTPOSTALCODE]	= " 1010";//MANDATORIO.
	PayLParams[CSSTPOSTALCODE]	= " 1010";//MANDATORIO.
             
	PayLParams[CSBTSTATE]		= "B";//MANDATORIO
	PayLParams[CSSTSTATE]		= "B";//MANDATORIO
             
	PayLParams[CSBTSTREET1]		= "Cerrito 740";//MANDATORIO.
	PayLParams[CSSTSTREET1]		= "Cerrito 740";//MANDATORIO.
             
	PayLParams[CSBTCUSTOMERID]	= "453458";; //MANDATORIO.
	PayLParams[CSBTIPADDRESS]	= "192.0.0.4"; //MANDATORIO.       
	PayLParams[CSPTCURRENCY]	= "ARS";//MANDATORIO.      
	PayLParams[CSPTGRANDTOTALAMOUNT]= "125.38";//MANDATORIO.
	PayLParams[CSMDD7		]	="";//NO MANDATORIO.        
	PayLParams[CSMDD8		]	="Y"; //NO MANDATORIO.       
	PayLParams[CSMDD9		]	="";//NO MANDATORIO.       
	PayLParams[CSMDD10		]	="";//NO MANDATORIO.      
	PayLParams[CSMDD11		]	="";//NO MANDATORIO.
	PayLParams[STCITY		]	="rosario";//MANDATORIO.       

	PayLParams[STCOUNTRY	]	="";//MANDATORIO.      
	PayLParams[STEMAIL		]	="jose@gmail.com";//MANDATORIO.        
	PayLParams[STFIRSTNAME	]	="Jose";//MANDATORIO.        
	PayLParams[STLASTNAME	]	="Perez";//MANDATORIO.      
	PayLParams[STPHONENUMBER]	= "541155893737";//MANDATORIO.        
	PayLParams[STPOSTALCODE	]	= "1414";//MANDATORIO.        
	PayLParams[STSTATE		]	="D";//MANDATORIO     

	PayLParams[STSTREET1	]	="San Martín 123";//MANDATORIO.       
	PayLParams[CSMDD12		]	= "";//NO MADATORIO.     
	PayLParams[CSMDD13		]	= "";//NO MANDATORIO.     
	PayLParams[CSMDD14		]	= "";//NO MANDATORIO.      
	PayLParams[CSMDD15		]	= "";//NO MANDATORIO.        
	PayLParams[CSMDD16		]	= "";//NO MANDATORIO.

	PayLParams[CSITPRODUCTCODE] = "electronic_good";//CONDICIONAL
	PayLParams[CSITPRODUCTDESCRIPTION]= "NOTEBOOK L845 SP4304LA DF TOSHIBA";//CONDICIONAL.     
	PayLParams[CSITPRODUCTNAME] = "NOTEBOOK L845 SP4304LA DF TOSHIBA";//CONDICIONAL.  
	PayLParams[CSITPRODUCTSKU]	= "LEVJNSL36GN";//CONDICIONAL.      
	PayLParams[CSITTOTALAMOUNT] = "1254.40";//CONDICIONAL.      
	PayLParams[CSITQUANTITY]	= "1";//CONDICIONAL.       
	PayLParams[CSITUNITPRICE]	= "1254.40";


	cout << "Loading library: " << DLL_PATH << "...\n";
	
	//HMODULE hDll = LoadLibrary( TEXT("TPConnectorDll.dll"));
	HMODULE hDll = LoadLibrary( DLL_PATH );
	if (hDll)
	{
		PF_GetDLLInterface pIntf = (PF_GetDLLInterface) GetProcAddress(hDll, "GetDLLInterface");
		TPCtor_Interface *pConntor = pIntf();
		if( pConntor ) {
			cout << "---------------- SendAuthorizeRequest()			.........\n";
			if(ret = pConntor->TPConnector_Init(endPointURL, strAthorization) == 0)
				cout << "---------------- SendAuthorizeRequest() OK\n";
			cout << "---------------- SendAuthorizeRequest_SetParams()	.........\n";
			if( ret = pConntor->SendAuthorizeRequest_SetParams(RParams, PayLParams) == 0)
				cout << "---------------- SendAuthorizeRequest_SetParams()	OK\n";

			cout << "---------------- SendAuthorizeRequest_Send()	..............\n";
			if( ret = pConntor->SendAuthorizeRequest_Send(output) == 0)
				cout << "---------------- SendAuthorizeRequest_Send()	OK\n";
			
			//Message = Solicitud de Autorizacion Registrada
			//RequestKey = 2aeaab24-45ea-1a77-a45d-59c6bedf8c9e
			//StatusCode = -1
			//URL_Request = https://developers.todopago.com.ar/formulario/commands?command=formulario&m=t147c50fb-d4f1-3693-48f4-027ca3024e2f
			//---------------- SendAuthorizeRequest_Send()    ..............
			//Message = Solicitud de Autorizacion Registrada
			//RequestKey = fca0ba76-5e07-3def-9583-450d4028026e
			//StatusCode = -1
			//URL_Request = https://developers.todopago.com.ar/formulario/commands?command=formulario&m=t5ed42051-6e80-71da-4237-233e6d62bf5d

			cout << "---------------- GetAuthorizeAnswer()	..............\n";

			GAAnswerInp[SECURITY]	= RParams[SECURITY]; //std::string(    "1234567890ABCDEF1234567890ABCDEF");
			GAAnswerInp[SESSION]	= ""; //NULL;
			GAAnswerInp[MERCHANT]	= string("2153");

			it = output.find(REQUEST_KEY);
			if( it !=  output.end() )
				GAAnswerInp[REQUEST_KEY] = it->second;
			else
				GAAnswerInp[REQUEST_KEY] = "";
			
			GAAnswerInp[ANSWER_KEY] = string("dee4d38b-d228-d077-5b55-2b1a12d24a16");
			
			if( ret = pConntor->GetAuthorizeAnswer_Send(GAAnswerInp, GAAnswerOut) == 0)
				cout << "---------------- GetAuthorizeAnswer()	OK\n";

			cout << "---------------- GetByOperationId_Send()	..............\n";

			GBiIDInp[GOPERATION_ID] = "01";
			GBiIDInp[MERCHANT]		= "2153";

			if( ret = pConntor->GetByOperationId_Send(GBiIDInp, GBiIDIOut) == 0 ) {
				cout << "---------------- GetByOperationId_Send()	OK\n";
				for(it=GBiIDIOut.begin(); it != GBiIDIOut.end(); it++)
					cout << it->first << " = " << it->second << endl;
			}
		}
		 
	}else {
		cout << "Error loading DLL\n";
		return -1;
	}


	return 0;
}

