// XML_To_ECM.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "XML_To_ECM.h"
#include <iostream>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

Vendor_t Ven;
group_t gro;
#define Nex_DEBUG

#ifdef Nex_DEBUG
#define Nex_PRINT(format,...) printf(">>Time: %s, Line: %05d, Function: %s: "format"", __TIME__, __LINE__, __FUNCTION__, ##__VA_ARGS__)
#else
#define Nex_PRINT(...) do{}while(0)
#endif


int LoadXMLFile(XMLDocument* doc,const char* xmlpath)
{
	if (doc->LoadFile(xmlpath))
	{
		Nex_PRINT("load xml file failed\n");
		return 0;
	}
	else
		Nex_PRINT("load xml OK\n");
	return 1;
}


int Get_VendorInfo(XMLDocument* doc,Vendor_t Vendor)
{
	const char* node;
	XMLElement* root = doc->RootElement();
	if (root)
	{
		XMLElement* vendor = root->FirstChildElement();
		if (vendor)
		{
			Vendor.FileVersion = vendor->FirstAttribute()->Value();
			Nex_PRINT("FileVersion = %s\n", Vendor.FileVersion);
			XMLElement* Id = vendor->FirstChildElement();
			if (Id)
			{
				node = Id->Name();
				Vendor.Id = (Id->GetText());
				Nex_PRINT("%s = %s\n", node, Vendor.Id);
				XMLElement* Name = Id->NextSiblingElement();
				if (Name)
				{
					node = Name->Name();
					Vendor.Name = Name->GetText();
					Nex_PRINT("%s = %s\n", node, Vendor.Name);
					XMLElement* Imagedata = Name->NextSiblingElement();
					if (Imagedata)
					{
						node = Imagedata->Name();
						Vendor.ImageData = Imagedata->GetText();
						Nex_PRINT("%s = %s\n", node, Vendor.ImageData);
					}
					else
					{
						Nex_PRINT("Error: no Vendor ImageData\n");
						return 0;
					}
				}
				else
				{
					Nex_PRINT("Error: no Vendor Name\n");
					return 0;
				}
			}
			else
			{
				Nex_PRINT("Error: no Vendor Id\n");
				return 0;
			}
		}
		else
		{
			Nex_PRINT("Error: no Vendor node\n");
			return 0;
		}
	}
	else
	{
		Nex_PRINT("Error: no root node,please check xml file or LoadFile first\n");
		return 0;
	}
	return 1;
}

int Get_GroupInfo(XMLDocument* doc,group_t group)
{
	const char* node;
	XMLElement* Type = doc->
	if (Type)
	{

	}

	return 1;
}



int main()
{
	
	XMLDocument docm;

	LoadXMLFile(&docm, "../DM3E_V1.70_Example.xml");
	
	Get_VendorInfo(&docm, Ven);

	Get_GroupInfo(&docm, gro);
}


