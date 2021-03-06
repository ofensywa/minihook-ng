#include "MenuElem.h"

CMenuElem gMenu(GLOBALMENU_TITLE, ELEM_BASEMENU, NULL);


CMenuElem::CMenuElem(std::string sText, enum ELEM_TYPE eType, void* pExtra) {
	sDisplayText = sText;
	ElemType = eType;
	iMenuIndex = 0;
	pPrevMenu = NULL;

	switch(eType) {
		case ELEM_BASEMENU: {
			bShow = false;
		}
		case ELEM_SUBMENU: {
			pCurMenu = NULL;
		}
		case ELEM_VALUE: {
			fMinimumValue = 0.0f;
			fMaximumValue = 1.0f;
			pfCurrentValue = (float*)pExtra;
			break;
		}

		case ELEM_CALLBACK: {
			pfCurrentValue = NULL;
			pCallbackFunction = (tMenuCallback)pExtra;
			break;
		}
	}
}

void CMenuElem::Initialize() {
	if(ElemType == ELEM_BASEMENU) {
		pCurMenu = this;
		pPrevMenu = this;
	}
}

void CMenuElem::AddElement(CMenuElem rElem) {
	vElems.push_back(rElem);
	vElems.back().pPrevMenu = this;
}

float CMenuElem::SetMinimumValue(float fMin) {
	float fPrevious = 0.0f;

	if(ElemType == ELEM_VALUE) {
		fPrevious = fMinimumValue;
		fMinimumValue = fMin;

		if(*pfCurrentValue < fMinimumValue) {
			*pfCurrentValue = fMinimumValue;
		}
	}

	return fPrevious;
}

float CMenuElem::SetMaximumValue(float fMax) {
	float fPrevious = 0.0f;

	if(ElemType == ELEM_VALUE) {
		fPrevious = fMaximumValue;
		fMaximumValue = fMax;

		if(*pfCurrentValue > fMaximumValue) {
			*pfCurrentValue = fMaximumValue;
		}
	}

	return fPrevious;
}

