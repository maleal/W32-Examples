#include "stdafx.h"
#include "AuthorizeRequest.h"
#include "util.h"
#include "TPConnectorDll.h"

using namespace std;
extern map<string, HWND> GlbalConfigTextBoxes;
extern map<string, HWND> SendAthRTextBoxes_Req;
extern map<string, HWND> SendAthRTextBoxes_PyL;

extern map<string, HWND> CyberSource_TextBoxes;
extern map<string, HWND> Retail_TextBoxes;

BOOL CreateSendAthReques_TextBoxes(map<string, HWND> &TextBoxes, map<string, HWND> &TextBoxesPyLoad, HWND hTab ) {

	// Here are the HardCodeee ....
	wstring SESS(TEXT("ABCDEF-1234-12221-FDE1-00000200"));
	wstring SECU(TEXT("912EC803B2CE49E4A541068D495AB570"));
	wstring MERC(TEXT("2153"));
	wstring U_OK(TEXT("http://google.com"));
	wstring U_ER(TEXT("http://www.coco.com"));
	wstring ENCO(TEXT("XML"));
	//End Here are the HardCodeee	

	

	HWND eti4 =  Create_Label(FALSE, hTab, L"SESSION", 20, 60, 130, 20);
	HWND hwnTxEd_SESSION = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 60, 300, 20,
	hTab, (HMENU) IDC_REQUEST_SESSION, NULL, NULL);
	SetTextinTextBox(hwnTxEd_SESSION, SESS);

	TextBoxes["LSESSION"] = eti4;
	TextBoxes[SESSION] = hwnTxEd_SESSION;
		
	HWND eti3 =  Create_Label(FALSE,hTab, L"SECURITY", 20, 90, 130, 20);
	HWND hwnTxEd_SECURITY = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 90, 300, 20,
	hTab, (HMENU) IDC_REQUEST_SECURITY, NULL, NULL);
	SetTextinTextBox(hwnTxEd_SECURITY, SECU);
	TextBoxes["LSECURITY"] = eti3;
	TextBoxes[SECURITY] = hwnTxEd_SECURITY;

	HWND eti8 =  Create_Label(FALSE,hTab, L"ENCODING_METHOD", 20, 120, 130, 20);
	HWND hwnTxEd_ENCODING_METHOD = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 120, 300, 20,
	hTab, (HMENU) IDC_REQUEST_ENCODING_METHOD, NULL, NULL);
	SetTextinTextBox(hwnTxEd_ENCODING_METHOD, ENCO);
	TextBoxes["LENCODING_METHOD"] = eti8;
	TextBoxes[ENCODING_METHOD] = hwnTxEd_ENCODING_METHOD;
	
	HWND eti5 =  Create_Label(FALSE,hTab, L"MERCHANT ", 20, 150, 130, 20);
	HWND hwnTxEd_MERCHANT = CreateWindowEx(WS_EX_CLIENTEDGE, L"edit", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 150, 300, 20,
	//hTab, (HMENU) IDC_REQUEST_MERCHANT, (HINSTANCE) GetWindowLong (hTab, GWL_HINSTANCE), NULL);
	hTab, (HMENU) IDC_REQUEST_MERCHANT, NULL, NULL);
	SetTextinTextBox(hwnTxEd_MERCHANT, MERC);
	TextBoxes["LMERCHANT"] = eti5;
	TextBoxes[MERCHANT] = hwnTxEd_MERCHANT;

	HWND eti6 =  Create_Label(FALSE,hTab, L"URL_OK", 20, 180, 130, 20);
	HWND hwnTxEd_URL_OK = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 180, 300, 20,
	hTab, (HMENU) IDC_REQUEST_URL_OK, NULL, NULL);
	SetTextinTextBox(hwnTxEd_URL_OK, U_OK);
	TextBoxes["LURL_OK"] = eti6;
	TextBoxes[URL_OK] = hwnTxEd_URL_OK;

	HWND eti7 =  Create_Label(FALSE,hTab, L"URL_ERROR", 20, 210, 130, 20);
	HWND hwnTxEd_URL_ERROR = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 210, 300, 20,
	hTab, (HMENU) IDC_REQUEST_URL_ERROR, NULL, NULL);
	SetTextinTextBox(hwnTxEd_URL_ERROR, U_ER);
	TextBoxes["LURL_ERROR"] = eti7;
	TextBoxes[URL_ERROR] = hwnTxEd_URL_ERROR;
		

	/*
	PayLParams[EMAILCLIENTE]	= "client_email@dominio.com";
	PayLParams[AMOUNT]			= "55";
	PayLParams[CURRENCYCODE]	= "032";
	PayLParams[OPERATIONID]		= "01";
	PayLParams[PAYL_MERCHANT]	= "2153";
	*/
	wstring EMAI(TEXT("client_email@dominio.com"));
	wstring AMOU(TEXT("55"));
	wstring CURR(TEXT("032"));
	wstring OPER(TEXT("01"));
	wstring PAYL(TEXT("2153"));

	HWND eti9 =  Create_Label(FALSE,hTab, L"EMAILCLIENTE", 500, 60, 130, 20);
	HWND hwnTxEd_EMAILCLIENTE = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	640, 60, 300, 20,
	hTab, (HMENU) IDC_REQUEST_EMAILCLIENTE, NULL, NULL);
	SetTextinTextBox(hwnTxEd_EMAILCLIENTE, EMAI);
	TextBoxesPyLoad["LEMAILCLIENTE"] = eti9;
	TextBoxesPyLoad[EMAILCLIENTE] = hwnTxEd_EMAILCLIENTE;

	HWND eti10 =  Create_Label(FALSE,hTab, L"AMOUNT", 500, 90, 130, 20);
	HWND hwnTxEd_AMOUNT = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	640, 90, 300, 20,
	hTab, (HMENU) IDC_REQUEST_AMOUNT, NULL, NULL);
	SetTextinTextBox(hwnTxEd_AMOUNT, AMOU);
	TextBoxesPyLoad["LAMOUNT"] = eti10;
	TextBoxesPyLoad[AMOUNT] = hwnTxEd_AMOUNT;
	
	HWND eti11 =  Create_Label(FALSE,hTab, L"CURRENCYCODE", 500, 120, 130, 20);
	HWND hwnTxEd_CURRENCYCODE = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	640, 120, 300, 20,
	hTab, (HMENU) IDC_REQUEST_CURRENCYCODE, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CURRENCYCODE, CURR);
	TextBoxesPyLoad["LCURRENCYCODE"] = eti11;
	TextBoxesPyLoad[CURRENCYCODE] = hwnTxEd_CURRENCYCODE;

	HWND eti12 =  Create_Label(FALSE,hTab, L"OPERATIONID", 500, 150, 130, 20);
	HWND hwnTxEd_OPERATIONID = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	640, 150, 300, 20,
	hTab, (HMENU) IDC_REQUEST_OPERATIONID, NULL, NULL);
	SetTextinTextBox(hwnTxEd_OPERATIONID, OPER);
	TextBoxesPyLoad["LOPERATIONID"] = eti12;
	TextBoxesPyLoad[OPERATIONID] = hwnTxEd_OPERATIONID;

	
	HWND eti13 =  Create_Label(FALSE,hTab, L"PAYL_MERCHANT", 500, 180, 130, 20);
	HWND hwnTxEd_PAYL_MERCHANT = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	640, 180, 300, 20,
	hTab, (HMENU) IDC_REQUEST_PAYL_MERCHANT, NULL, NULL);
	SetTextinTextBox(hwnTxEd_PAYL_MERCHANT, PAYL);
	TextBoxesPyLoad["LPAYL_MERCHANT"] = eti13;
	TextBoxesPyLoad[PAYL_MERCHANT] = hwnTxEd_PAYL_MERCHANT;
	
	return TRUE;
}

BOOL CreateRetail_TextBoxes(map<string, HWND> &TextBoxes, HWND hTab) {
	
	//Firsht column
	// Here are the HardCodeee ....
	wstring CSSTCI			(TEXT("Villa General Belgrano"));		//MANDATORIO.
	wstring CSSTCOUN		(TEXT("AR"));							//MANDATORIO. Código ISO.
	wstring CSSTSTR1		(TEXT("Cerrito 740"));					//MANDATORIO.
	wstring CSSTSTR2		(TEXT("Cerrito 740"));					//MANDATORIO.
	wstring CSSTPOSTALC		(TEXT("1010"));						//MANDATORIO.
	wstring CSSTFIRSTN		(TEXT("Juan"));						//MANDATORIO.    
	wstring CSSTLASTN		(TEXT("Perez"));						//MANDATORIO.
	wstring CSSTPHONENUM	(TEXT("541160913988"));					//MANDATORIO. 
	wstring CSSTST			(TEXT( "B"));							//MANDATORIO
	wstring CSSTEM			(TEXT( "todopago@hotmail.com"));		//MANDATORIO.
	//End Here are the HardCodeee

	HWND eti1 =  Create_Label(FALSE, hTab, L"CSSTCITY", 20, 60, 130, 20);
	HWND hwnTxEd_CSBTCITY = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 60, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTCITY, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTCITY, CSSTCI);
	TextBoxes["LCSSTCITY"] = eti1;
	TextBoxes[CSSTCITY] = hwnTxEd_CSBTCITY;
		
	HWND eti2 =  Create_Label(FALSE, hTab, L"CSSTCOUNTRY", 20, 90, 130, 20);
	HWND hwnTxEd_CSBTCOUNTRY = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 90, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTCOUNTRY, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTCOUNTRY, CSSTCOUN);
	TextBoxes["LCSSTCOUNTRY"] = eti2;
	TextBoxes[CSSTCOUNTRY] = hwnTxEd_CSBTCOUNTRY;

	HWND eti3 =  Create_Label(FALSE,hTab, L"CSSTSTREET1", 20, 120, 130, 20);
	HWND hwnTxEd_CSBTSTREET1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 120, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTSTREET1, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTSTREET1, CSSTSTR1);
	TextBoxes["LCSSTSTREET1"] = eti3;
	TextBoxes[CSSTSTREET1] = hwnTxEd_CSBTSTREET1;
	
	HWND eti4 =  Create_Label(FALSE,hTab, L"CSSTSTREET2 ", 20, 150, 130, 20);
	HWND hwnTxEd_CSBTSTREET2 = CreateWindowEx(WS_EX_CLIENTEDGE, L"edit", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 150, 300, 20,
	//hTab, (HMENU) IDC_REQUEST_MERCHANT, (HINSTANCE) GetWindowLong (hTab, GWL_HINSTANCE), NULL);
	hTab, (HMENU) IDC_CYBER_CSBTSTREET2, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTSTREET2, CSSTSTR2);
	TextBoxes["LCSSTSTREET2"] = eti4;
	TextBoxes[CSSTSTREET2] = hwnTxEd_CSBTSTREET2;

	HWND eti5 =  Create_Label(FALSE,hTab, L"CSSTPOSTALCODE", 20, 180, 130, 20);
	HWND hwnTxEd_CSBTPOSTALCODE = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 180, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTPOSTALCODE, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTPOSTALCODE, CSSTPOSTALC);
	TextBoxes["LCSSTPOSTALCODE"] = eti5;
	TextBoxes[CSSTPOSTALCODE] = hwnTxEd_CSBTPOSTALCODE;

	HWND eti6 =  Create_Label(FALSE,hTab, L"CSSTFIRSTNAME", 20, 210, 130, 20);
	HWND hwnTxEd_CSBTFIRSTNAME = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 210, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTFIRSTNAME, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTFIRSTNAME, CSSTFIRSTN);
	TextBoxes["LCSSTFIRSTNAME"] = eti6;
	TextBoxes[CSSTFIRSTNAME] = hwnTxEd_CSBTFIRSTNAME;
		
	HWND eti7 =  Create_Label(FALSE,hTab, L"CSSTLASTNAME", 20, 240, 130, 20);
	HWND hwnTxEd_CSBTLASTNAME = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 240, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTLASTNAME, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTLASTNAME, CSSTLASTN);
	TextBoxes["LCSSTLASTNAME"] = eti7;
	TextBoxes[CSSTLASTNAME] = hwnTxEd_CSBTLASTNAME;
		
	HWND eti8 =  Create_Label(FALSE,hTab, L"CSSTPHONENUMBER", 20, 280, 130, 20);
	HWND hwnTxEd_CSBTPHONENUMBER = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 280, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTPHONENUMBER, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTPHONENUMBER, CSSTPHONENUM);
	TextBoxes["LCSSTPHONENUMBER"] = eti8;
	TextBoxes[CSSTPHONENUMBER] = hwnTxEd_CSBTPHONENUMBER;

	HWND eti9 =  Create_Label(FALSE,hTab, L"CSSTSTATE", 20, 310, 130, 20);
	HWND hwnTxEd_CSBTSTATE = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 310, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTSTATE, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTSTATE, CSSTST);
	TextBoxes["LCSSTSTATE"] = eti9;
	TextBoxes[CSSTSTATE] = hwnTxEd_CSBTSTATE;

	HWND eti10 =  Create_Label(FALSE,hTab, L"CSSTEMAIL", 20, 340, 130, 20);
	HWND hwnTxEd_CSBTEMAIL = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 340, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTEMAIL, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTEMAIL, CSSTEM);
	TextBoxes["LCSSTEMAIL"] = eti10;
	TextBoxes[CSSTEMAIL] = hwnTxEd_CSBTEMAIL;
	
	//Second column
	
	wstring CSITPRODUCTC = L"electronic_good";//CONDICIONAL
	wstring CSITPRODUCTDESCRIPT = L"Hecho Por Mario Leal Fuentes";//CONDICIONAL.
	wstring CSITPRODUCTN = L"Boost STL";//CONDICIONAL.
	wstring CSITPRODUCTS = L"Linux 1234";//CONDICIONAL.
	wstring CSITTOTALAMOU = L"1.00";//CONDICIONAL.
	wstring CSITQUANTI = L"1";//CONDICIONAL.
	wstring CSITUNITPRI = L"1.00";
	wstring _CSMDD12		= L"Villa San Lorenzo";//NO MADATORIO.
	wstring _CSMDD13		= L"AR";//NO MANDATORIO.
	wstring _CSMDD14		= L"todopago@esta.com";//NO MANDATORIO.

	/*
	  
const std::string CSMDD15		= "CSMDD15";//NO MANDATORIO.        
const std::string CSMDD16		= "CSMDD16";//NO MANDATORIO.
	*/
	HWND eti11 =  Create_Label(FALSE, hTab, L"CSITPRODUCTCODE", 500, 60, 130, 20);
	HWND hwnTxEd_CSITPRODUCTCODE = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 60, 300, 20,
	hTab, (HMENU) IDC_RET_CSITPRODUCTCODE, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSITPRODUCTCODE, CSITPRODUCTC);
	TextBoxes["LCSITPRODUCTCODE"] = eti11;
	TextBoxes[CSITPRODUCTCODE] = hwnTxEd_CSITPRODUCTCODE;

	HWND eti12 =  Create_Label(FALSE, hTab, L"CSITPRODUCTDESCRIPTION", 500, 90, 130, 20);
	HWND hwnTxEd_CSITPRODUCTDESCRIPTION = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 90, 300, 20,
	hTab, (HMENU) IDC_RET_CSITPRODUCTDESCRIPTION, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSITPRODUCTDESCRIPTION, CSITPRODUCTDESCRIPT);
	TextBoxes["LCSITPRODUCTDESCRIPTION"] = eti12;
	TextBoxes[CSITPRODUCTDESCRIPTION] = hwnTxEd_CSITPRODUCTDESCRIPTION;

	HWND eti13 =  Create_Label(FALSE, hTab, L"CSITPRODUCTNAME", 500, 120, 130, 20);
	HWND hwnTxEd_CSITPRODUCTNAME = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 120, 300, 20,
	hTab, (HMENU) IDC_RET_CSITPRODUCTNAME, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSITPRODUCTNAME, CSITPRODUCTN);
	TextBoxes["LCSITPRODUCTNAME"] = eti13;
	TextBoxes[CSITPRODUCTNAME] = hwnTxEd_CSITPRODUCTNAME;


	HWND eti14 =  Create_Label(FALSE, hTab, L"CSITPRODUCTSKU", 500, 150, 130, 20);
	HWND hwnTxEd_CSITPRODUCTSKU = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 150, 300, 20,
	hTab, (HMENU) IDC_RET_CSITPRODUCTSKU, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSITPRODUCTSKU, CSITPRODUCTS);
	TextBoxes["LCSITPRODUCTSKU"] = eti14;
	TextBoxes[CSITPRODUCTSKU] = hwnTxEd_CSITPRODUCTSKU;

	HWND eti15 =  Create_Label(FALSE, hTab, L"CSITTOTALAMOUNT", 500, 180, 130, 20);
	HWND hwnTxEd_CSITTOTALAMOUNT = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 180, 300, 20,
	hTab, (HMENU) IDC_RET_CSITTOTALAMOUNT, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSITTOTALAMOUNT, CSITTOTALAMOU);
	TextBoxes["LCSITTOTALAMOUNT"] = eti15;
	TextBoxes[CSITTOTALAMOUNT] = hwnTxEd_CSITTOTALAMOUNT;

	HWND eti16 =  Create_Label(FALSE, hTab, L"CSITQUANTITY", 500, 210, 130, 20);
	HWND hwnTxEd_CSITQUANTITY = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 210, 300, 20,
	hTab, (HMENU) IDC_RET_CSITQUANTITY, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSITQUANTITY, CSITQUANTI);
	TextBoxes["LCSITQUANTITY"] = eti16;
	TextBoxes[CSITQUANTITY] = hwnTxEd_CSITQUANTITY;

	HWND eti17 =  Create_Label(FALSE, hTab, L"CSITUNITPRICE", 500, 240, 130, 20);
	HWND hwnTxEd_CSITUNITPRICE = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 240, 300, 20,
	hTab, (HMENU) IDC_RET_CSITUNITPRICE, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSITUNITPRICE, CSITUNITPRI);
	TextBoxes["LCSITUNITPRICE"] = eti17;
	TextBoxes[CSITUNITPRICE] = hwnTxEd_CSITUNITPRICE;

	
	HWND eti18 =  Create_Label(FALSE, hTab, L"CSMDD12", 500, 270, 130, 20);
	HWND hwnTxEd_CSMDD12 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 270, 300, 20,
	hTab, (HMENU) IDC_RET_CSMDD12, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSMDD12, _CSMDD12);
	TextBoxes["LCSMDD12"] = eti18;
	TextBoxes[CSMDD12] = hwnTxEd_CSMDD12;

	HWND eti19 =  Create_Label(FALSE, hTab, L"CSMDD13", 500, 300, 130, 20);
	HWND hwnTxEd_CSMDD13 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 300, 300, 20,
	hTab, (HMENU) IDC_RET_CSMDD13, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSMDD13, _CSMDD13);
	TextBoxes["LCSMDD13"] = eti19;
	TextBoxes[CSMDD13] = hwnTxEd_CSMDD13;

	HWND eti20 =  Create_Label(FALSE, hTab, L"CSMDD14", 500, 330, 130, 20);
	HWND hwnTxEd_CSMDD14 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 330, 300, 20,
	hTab, (HMENU) IDC_RET_CSMDD14, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSMDD14, _CSMDD14);
	TextBoxes["LCSMDD14"] = eti20;
	TextBoxes[CSMDD14] = hwnTxEd_CSMDD14;


	return TRUE;

	
}


BOOL CreateCyberSource_TextBoxes(map<string, HWND> &TextBoxes, HWND hTab) {
	
	// Here are the HardCodeee ....
	wstring CSBTCI			(TEXT("Villa General Belgrano"));		//MANDATORIO.
	wstring CSBTCOUN		(TEXT("AR"));							//MANDATORIO. Código ISO.
	wstring CSBTSTR1		(TEXT("Cerrito 740"));					//MANDATORIO.
	wstring CSBTSTR2		(TEXT("Cerrito 740"));					//MANDATORIO.
	wstring CSBTPOSTALC		(TEXT("1010"));						//MANDATORIO.
	wstring CSBTFIRSTN		(TEXT("Juan"));						//MANDATORIO.    
	wstring CSBTLASTN		(TEXT("Perez"));						//MANDATORIO.
	wstring CSBTPHONENUM	(TEXT("541160913988"));					//MANDATORIO. 
	wstring CSBTST			(TEXT( "B"));							//MANDATORIO
	wstring CSBTEM			(TEXT( "todopago@hotmail.com"));		//MANDATORIO.
	//End Here are the HardCodeee	

	HWND eti1 =  Create_Label(FALSE, hTab, L"CSBTCITY", 20, 60, 130, 20);
	HWND hwnTxEd_CSBTCITY = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 60, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTCITY, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTCITY, CSBTCI);
	TextBoxes["LCSBTCITY"] = eti1;
	TextBoxes[CSBTCITY] = hwnTxEd_CSBTCITY;
		
	HWND eti2 =  Create_Label(FALSE, hTab, L"CSBTCOUNTRY", 20, 90, 130, 20);
	HWND hwnTxEd_CSBTCOUNTRY = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 90, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTCOUNTRY, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTCOUNTRY, CSBTCOUN);
	TextBoxes["LCSBTCOUNTRY"] = eti2;
	TextBoxes[CSBTCOUNTRY] = hwnTxEd_CSBTCOUNTRY;

	HWND eti3 =  Create_Label(FALSE,hTab, L"CSBTSTREET1", 20, 120, 130, 20);
	HWND hwnTxEd_CSBTSTREET1 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 120, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTSTREET1, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTSTREET1, CSBTSTR1);
	TextBoxes["LCSBTSTREET1"] = eti3;
	TextBoxes[CSBTSTREET1] = hwnTxEd_CSBTSTREET1;
	
	HWND eti4 =  Create_Label(FALSE,hTab, L"CSBTSTREET2 ", 20, 150, 130, 20);
	HWND hwnTxEd_CSBTSTREET2 = CreateWindowEx(WS_EX_CLIENTEDGE, L"edit", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 150, 300, 20,
	//hTab, (HMENU) IDC_REQUEST_MERCHANT, (HINSTANCE) GetWindowLong (hTab, GWL_HINSTANCE), NULL);
	hTab, (HMENU) IDC_CYBER_CSBTSTREET2, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTSTREET2, CSBTSTR2);
	TextBoxes["LCSBTSTREET2"] = eti4;
	TextBoxes[CSBTSTREET2] = hwnTxEd_CSBTSTREET2;

	HWND eti5 =  Create_Label(FALSE,hTab, L"CSBTPOSTALCODE", 20, 180, 130, 20);
	HWND hwnTxEd_CSBTPOSTALCODE = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 180, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTPOSTALCODE, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTPOSTALCODE, CSBTPOSTALC);
	TextBoxes["LCSBTPOSTALCODE"] = eti5;
	TextBoxes[CSBTPOSTALCODE] = hwnTxEd_CSBTPOSTALCODE;

	HWND eti6 =  Create_Label(FALSE,hTab, L"CSBTFIRSTNAME", 20, 210, 130, 20);
	HWND hwnTxEd_CSBTFIRSTNAME = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 210, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTFIRSTNAME, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTFIRSTNAME, CSBTFIRSTN);
	TextBoxes["LCSBTFIRSTNAME"] = eti6;
	TextBoxes[CSBTFIRSTNAME] = hwnTxEd_CSBTFIRSTNAME;
		
	HWND eti7 =  Create_Label(FALSE,hTab, L"CSBTLASTNAME", 20, 240, 130, 20);
	HWND hwnTxEd_CSBTLASTNAME = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 240, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTLASTNAME, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTLASTNAME, CSBTLASTN);
	TextBoxes["LCSBTLASTNAME"] = eti7;
	TextBoxes[CSBTLASTNAME] = hwnTxEd_CSBTLASTNAME;
		
	HWND eti8 =  Create_Label(FALSE,hTab, L"CSBTPHONENUMBER", 20, 280, 130, 20);
	HWND hwnTxEd_CSBTPHONENUMBER = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 280, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTPHONENUMBER, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTPHONENUMBER, CSBTPHONENUM);
	TextBoxes["LCSBTPHONENUMBER"] = eti8;
	TextBoxes[CSBTPHONENUMBER] = hwnTxEd_CSBTPHONENUMBER;

	HWND eti9 =  Create_Label(FALSE,hTab, L"CSBTSTATE", 20, 310, 130, 20);
	HWND hwnTxEd_CSBTSTATE = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 310, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTSTATE, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTSTATE, CSBTST);
	TextBoxes["LCSBTSTATE"] = eti9;
	TextBoxes[CSBTSTATE] = hwnTxEd_CSBTSTATE;

	HWND eti10 =  Create_Label(FALSE,hTab, L"CSBTEMAIL", 20, 340, 130, 20);
	HWND hwnTxEd_CSBTEMAIL = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	150, 340, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTEMAIL, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTEMAIL, CSBTEM);
	TextBoxes["LCSBTEMAIL"] = eti10;
	TextBoxes[CSBTEMAIL] = hwnTxEd_CSBTEMAIL;
	
	/*
	*/
	wstring CSPTGRANDTOTALAMO(TEXT( "125.38"));					//MANDATORIO.
	wstring CSBTCUSTOME	(TEXT( "453458"));						//MANDATORIO.
	wstring CSBTIPADDR	(TEXT( "192.0.0.4"));					//MANDATORIO.       
	wstring CSPTCURRE	(TEXT( "ARS"));							//MANDATORIO.  
	wstring _CSMDD6			(TEXT(""));								//NO MANDATORIO.   
	//stkexpress
	wstring _CSMDD7			(TEXT(""));								//NO MANDATORIO.        
	wstring _CSMDD8			(TEXT(""));							//NO MANDATORIO.       
	wstring _CSMDD9			(TEXT("Y"));								//NO MANDATORIO.       
	wstring _CSMDD10		(TEXT(""));								//NO MANDATORIO.      
	wstring _CSMDD11		(TEXT(""));								//NO MANDATORIO.
	
	
	HWND eti11 =  Create_Label(FALSE, hTab, L"CSPTGRANDTOTALAMOUNT", 500, 60, 130, 20);
	HWND hwnTxEd_CSPTGRANDTOTALAMOUNT = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 60, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSPTGRANDTOTALAMOUNT, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSPTGRANDTOTALAMOUNT, CSPTGRANDTOTALAMO);
	TextBoxes["LCSPTGRANDTOTALAMOUNT"] = eti11;
	TextBoxes[CSPTGRANDTOTALAMOUNT] = hwnTxEd_CSPTGRANDTOTALAMOUNT;

	HWND eti12 =  Create_Label(FALSE, hTab, L"CSBTCUSTOMERID", 500, 90, 130, 20);
	HWND hwnTxEd_CSBTCUSTOMERID = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 90, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTCUSTOMERID, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTCUSTOMERID, CSBTCUSTOME);
	TextBoxes["LCSBTCUSTOMERID"] = eti12;
	TextBoxes[CSBTCUSTOMERID] = hwnTxEd_CSBTCUSTOMERID;

	HWND eti13 =  Create_Label(FALSE, hTab, L"CSBTIPADDRESS", 500, 120, 130, 20);
	HWND hwnTxEd_CSBTIPADDRESS = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 120, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSBTIPADDRESS, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSBTIPADDRESS, CSBTIPADDR);
	TextBoxes["LCSBTIPADDRESS"] = eti13;
	TextBoxes[CSBTIPADDRESS] = hwnTxEd_CSBTIPADDRESS;

	HWND eti14 =  Create_Label(FALSE, hTab, L"CSPTCURRENCY", 500, 150, 130, 20);
	HWND hwnTxEd_CSPTCURRENCY = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 150, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSPTCURRENCY, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSPTCURRENCY, CSPTCURRE);
	TextBoxes["LCSPTCURRENCY"] = eti14;
	TextBoxes[CSPTCURRENCY] = hwnTxEd_CSPTCURRENCY;

	HWND eti15 =  Create_Label(FALSE, hTab, L"CSMDD6", 500, 180, 130, 20);
	HWND hwnTxEd_CSMDD6 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 180, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSMDD6, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSMDD6, _CSMDD6);
	TextBoxes["LCSMDD6"] = eti15;
	TextBoxes[CSMDD6] = hwnTxEd_CSMDD6;

	HWND eti16 =  Create_Label(FALSE, hTab, L"CSMDD7", 500, 210, 130, 20);
	HWND hwnTxEd_CSMDD7 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 210, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSMDD7, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSMDD7, _CSMDD7);
	TextBoxes["LCSMDD7"] = eti16;
	TextBoxes[CSMDD7] = hwnTxEd_CSMDD7;

	HWND eti17 =  Create_Label(FALSE, hTab, L"CSMDD8", 500, 240, 130, 20);
	HWND hwnTxEd_CSMDD8 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 240, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSMDD8, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSMDD8, _CSMDD8);
	TextBoxes["LCSMDD8"] = eti17;
	TextBoxes[CSMDD8] = hwnTxEd_CSMDD8;

	HWND eti18 =  Create_Label(FALSE, hTab, L"CSMDD9", 500, 270, 130, 20);
	HWND hwnTxEd_CSMDD9 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 270, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSMDD9, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSMDD9, _CSMDD9);
	TextBoxes["LCSMDD9"] = eti18;
	TextBoxes[CSMDD9] = hwnTxEd_CSMDD9;

	HWND eti19 =  Create_Label(FALSE, hTab, L"CSMDD10", 500, 300, 130, 20);
	HWND hwnTxEd_CSMDD10 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 300, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSMDD10, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSMDD10, _CSMDD10);
	TextBoxes["LCSMDD10"] = eti19;
	TextBoxes[CSMDD10] = hwnTxEd_CSMDD10;

	HWND eti20 =  Create_Label(FALSE, hTab, L"CSMDD11", 500, 330, 130, 20);
	HWND hwnTxEd_CSMDD11 = CreateWindowEx(WS_EX_CLIENTEDGE, L"EDIT", NULL, 
	 WS_CHILD | WS_BORDER | WS_TABSTOP | WS_GROUP,
	680, 330, 300, 20,
	hTab, (HMENU) IDC_CYBER_CSMDD11, NULL, NULL);
	SetTextinTextBox(hwnTxEd_CSMDD11, _CSMDD11);
	TextBoxes["LCSMDD11"] = eti20;
	TextBoxes[CSMDD11] = hwnTxEd_CSMDD11;

	return TRUE;
}

BOOL SendAuthorizeRequest(map<string, string> &Output) {
					map<string, HWND>::iterator it;
					wchar_t text[512];
					
					map<string, wstring>sendAthRMap;
					map<string, wstring>req_PyL;
					string strEndP, strAth;
					int ret, cTxtLen;
		

					it = GlbalConfigTextBoxes.find("End_Point");
					if( it != GlbalConfigTextBoxes.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							strEndP = ws2s(wstring(text));
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'End Point'"),  TEXT("End Point"),  MB_DEFBUTTON2);
							return FALSE;
						}
					}
					
					it = GlbalConfigTextBoxes.find("Prisma_Ath");
					if( it != GlbalConfigTextBoxes.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							strAth = ws2s(wstring(text));
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'Prisma Ath'"),  TEXT("Prisma Ath"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = SendAthRTextBoxes_Req.find(SESSION);
					if( it != SendAthRTextBoxes_Req.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							sendAthRMap[SESSION]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'SESSION'"),  TEXT("SESSION"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = SendAthRTextBoxes_Req.find(SECURITY);
					if( it != SendAthRTextBoxes_Req.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							sendAthRMap[SECURITY]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'SECURITY'"),  TEXT("SECURITY"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = SendAthRTextBoxes_Req.find(ENCODING_METHOD);
					if( it != SendAthRTextBoxes_Req.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							//MessageBox(NULL, text,  text, MB_ICONWARNING | MB_CANCELTRYCONTINUE | MB_DEFBUTTON2);
							sendAthRMap[ENCODING_METHOD]=wstring(text, cTxtLen);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'ENCODING_METHOD'"),  TEXT("ENCODING_METHOD"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}
					
					it = SendAthRTextBoxes_Req.find(MERCHANT);
					if( it != SendAthRTextBoxes_Req.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							sendAthRMap[MERCHANT]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'MERCHANT'"),  TEXT("MERCHANT"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}
					
					it = SendAthRTextBoxes_Req.find(URL_OK);
					if( it != SendAthRTextBoxes_Req.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							sendAthRMap[URL_OK]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'URL_OK'"),  TEXT("URL_OK"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}
					it = SendAthRTextBoxes_Req.find(URL_ERROR);
					if( it != SendAthRTextBoxes_Req.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							sendAthRMap[URL_ERROR]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'URL_ERROR'"),  TEXT("URL_ERROR"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = SendAthRTextBoxes_PyL.find(EMAILCLIENTE);
					if( it != SendAthRTextBoxes_PyL.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[EMAILCLIENTE]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'EMAILCLIENTE'"),  TEXT("EMAILCLIENTE"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = SendAthRTextBoxes_PyL.find(AMOUNT);
					if( it != SendAthRTextBoxes_PyL.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[AMOUNT]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'AMOUNT'"),  TEXT("AMOUNT"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = SendAthRTextBoxes_PyL.find(CURRENCYCODE);
					if( it != SendAthRTextBoxes_PyL.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[CURRENCYCODE]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'CURRENCYCODE'"),  TEXT("CURRENCYCODE"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}
					
					it = SendAthRTextBoxes_PyL.find(OPERATIONID);
					if( it != SendAthRTextBoxes_PyL.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[OPERATIONID]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'OPERATIONID'"),  TEXT("OPERATIONID"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = SendAthRTextBoxes_PyL.find(PAYL_MERCHANT);
					if( it != SendAthRTextBoxes_PyL.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[PAYL_MERCHANT]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'PAYL_MERCHANT'"),  TEXT("PAYL_MERCHANT"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}
									
					
					it = CyberSource_TextBoxes.find(CSBTCITY);
					if( it != CyberSource_TextBoxes.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[CSBTCITY]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'CSBTCITY'"),  TEXT("CSBTCITY"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}
					
					it = CyberSource_TextBoxes.find(CSBTCOUNTRY);
					if( it != CyberSource_TextBoxes.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[CSBTCOUNTRY]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'CSBTCOUNTRY'"),  TEXT("CSBTCOUNTRY"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}
					it = CyberSource_TextBoxes.find(CSBTEMAIL);
					if( it != CyberSource_TextBoxes.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[CSBTEMAIL]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'CSBTEMAIL'"),  TEXT("CSBTEMAIL"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = CyberSource_TextBoxes.find(CSBTFIRSTNAME);
					if( it != CyberSource_TextBoxes.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[CSBTFIRSTNAME]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'CSBTFIRSTNAME'"),  TEXT("CSBTFIRSTNAME"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}
					
					it = CyberSource_TextBoxes.find(CSBTLASTNAME);
					if( it != CyberSource_TextBoxes.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[CSBTLASTNAME]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'CSBTLASTNAME'"),  TEXT("CSBTLASTNAME"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = CyberSource_TextBoxes.find(CSBTPHONENUMBER);
					if( it != CyberSource_TextBoxes.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[CSBTPHONENUMBER]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'CSBTPHONENUMBER'"),  TEXT("CSBTPHONENUMBER"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = CyberSource_TextBoxes.find(CSBTPOSTALCODE);
					if( it != CyberSource_TextBoxes.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[CSBTPOSTALCODE]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'CSBTPOSTALCODE'"),  TEXT("CSBTPOSTALCODE"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = CyberSource_TextBoxes.find(CSBTSTREET1);
					if( it != CyberSource_TextBoxes.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[CSBTSTREET1]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'CSBTSTREET1'"),  TEXT("CSBTSTREET1"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = CyberSource_TextBoxes.find(CSBTIPADDRESS);
					if( it != CyberSource_TextBoxes.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[CSBTIPADDRESS]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'CSBTIPADDRESS'"),  TEXT("CSBTIPADDRESS"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					it = CyberSource_TextBoxes.find(CSPTGRANDTOTALAMOUNT);
					if( it != CyberSource_TextBoxes.end() ) {
						cTxtLen = GetWindowTextLength(it->second);
						if( cTxtLen > 0 ) {
							GetWindowTextW(it->second, text, cTxtLen+1);
							req_PyL[CSPTGRANDTOTALAMOUNT]=wstring(text);
						}else{
							MessageBox(NULL, TEXT("Debe ingresar 'CSPTGRANDTOTALAMOUNT'"),  TEXT("CSPTGRANDTOTALAMOUNT"),  MB_DEFBUTTON2);
							return FALSE;;
						}
					}

					//Retail

					//End Retail


					HINSTANCE hinstLib;
					hinstLib = LoadLibrary(TEXT("ExLinkTPConnectorDll.dll"));
					if(hinstLib == NULL) {
						MessageBox(NULL, TEXT("No encuentra ExLinkTPConnectorDll"),  TEXT("ExLinkTPConnectorDll"),  MB_DEFBUTTON2);
						return FALSE;
						
					}
					
					PF_GetDLLInterface pIntf = (PF_GetDLLInterface) GetProcAddress(hinstLib, "GetDLLInterface");
					TPCtor_Interface *pConntor = pIntf();

					if( pConntor ) {
						if(ret = pConntor->TPConnector_Init(strEndP, strAth) == 0) {
							map<string, string>*Req = wsm2sm(sendAthRMap);
							map<string, string>*Pay = wsm2sm(req_PyL);
							if( ret = pConntor->SendAuthorizeRequest_SetParams( (*Req), (*Pay)) == 0) {
								pConntor->SendAuthorizeRequest_Send(Output);
								delete Req;
								delete Pay;
								return TRUE;
							}
							delete Req;
							delete Pay;
						}
					}
					return FALSE;
}
