// w32ConsoleTest_IpL.cpp : Defines the entry point for the console application.
// Developer: mariolealfuentes@gmail.com

#include "stdafx.h"
#include "TPConnectorDll.h"
#include <iostream>
//#include <Windows.h>


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int ret=0;

	TPCtor_Interface* pConntor = GetDLLInterface();
	

#ifdef _DEBUG
	//const std::string endPointURL		= "https://developers.todopago.com.ar/services/t/1.1//services/Authorize";
	const string endPointURL		= "https://developers.todopago.com.ar/services/t/1.1//services/";
	const string strAthorization	= "PRISMA f3d8b72c94ab4a06be2ef7c95490f7d3";
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


	cout << "---------------- SendAuthorizeRequest() .........\n";
	if(ret = pConntor->TPConnector_Init(endPointURL, strAthorization) == 0)
		cout << "---------------- SendAuthorizeRequest() OK\n";

	cout << "---------------- SendAuthorizeRequest_SetParams()	.........\n";
	if( ret = pConntor->SendAuthorizeRequest_SetParams(RParams, PayLParams) == 0)
		cout << "---------------- SendAuthorizeRequest_SetParams()	OK\n";

	cout << "---------------- SendAuthorizeRequest_Send()	..............\n";
	if( ret = pConntor->SendAuthorizeRequest_Send(output) == 0) {
		cout << "---------------- SendAuthorizeRequest_Send()	OK\n";
		for(it=output.begin(); it != output.end(); it++)
					cout << it->first << " = " << it->second << endl;
	}

	/*
	Del std::map output, con la key URL_Request, obtenmos la url de redireccion al formiulario de Todo Pago, en nuestro caso devolvio 
	'https://developers.todopago.com.ar/formulario/commands?command=formulario&m=tb5018c36-3a12-c102-6981-36eec856e056'
	a este hay que completarlo para asi obtener del GET el dato Answer, en nuestro caso obtuvimos:
	'http://www.coco.com/?Answer=b2a92181-0ed6-1bd3-21fa-abe1b5fd9fe5'
	*/
	
	GAAnswerInp[SECURITY]	= RParams[SECURITY]; //std::string(    "1234567890ABCDEF1234567890ABCDEF");
	GAAnswerInp[SESSION]	= ""; //NULL;
	GAAnswerInp[MERCHANT]	= string("2153");

	it = output.find(REQUEST_KEY);
	if( it !=  output.end() )
		GAAnswerInp[REQUEST_KEY] = it->second;
	else
		GAAnswerInp[REQUEST_KEY] = "";
	GAAnswerInp[ANSWER_KEY] = string("b2a92181-0ed6-1bd3-21fa-abe1b5fd9fe5");

	if( ret = pConntor->GetAuthorizeAnswer_Send(GAAnswerInp, GAAnswerOut) == 0) {
		cout << "---------------- GetAuthorizeAnswer()	OK\n";
		for(it=GAAnswerOut.begin(); it != GAAnswerOut.end(); it++)
					cout << it->first << " = " << it->second << endl;

	}



	return 0;
}

