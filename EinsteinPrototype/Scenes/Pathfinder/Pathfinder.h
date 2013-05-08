//
//  Pathfinder.h
//  EinsteinPrototype
//
//  Created by Farofa Studios on 8/23/12.
//  Copyright (c) 2012 Farofa Studios. All rights reserved.
//

#ifndef EinsteinPrototype_Pathfinder_h
#define EinsteinPrototype_Pathfinder_h

#include "cocos2d.h"
#include "AStar.h"
#include <vector>
#include <string>

using namespace cocos2d;

typedef enum{
	ICON_ACESSO_RESTRITO = 1,
	ICON_ELEVADOR = 2,
	ICON_ENTRADA = 3,
	ICON_SAIDA = 4,
	ICON_ESTACIONAMENTO = 5,
	ICON_ESCADA = 6,
	ICON_ESCADA_ROLANTE = 7,
	ICON_CAFE = 8,
	ICON_RESTAURANTE = 9,
	ICON_CAIXA_ELETRONICA = 10,
	ICON_FARMACIA = 11,
	ICON_EXAME = 12,
	ICON_CLINICA = 13,
	ICON_BANHEIRO = 14,
	ICON_PEDIATRIA = 15,
	ICON_FOTO = 16,
	ICON_OBRA_DE_ARTE = 17,
	ICON_RECEPCAO = 18,
	ICON_ESCULTURA = 19,
	ICON_APARTAMENTOS = 20,
	ICON_CABELEIREIRO = 21,
	ICON_PRESENTES = 22,
	ICON_JARDIM = 23,
	ICON_MATERNIDADE = 24,
	ICON_AUDITORIO = 25,
	ICON_SINAGOGA = 26
} MapIcons;

typedef enum{
	LINE_NORMAL,
	LINE_SHADOW,
	LINE_STEP
} LineType;

class Pathfinder : public CCNode{
    
public:
    Pathfinder();
    ~Pathfinder();
    
    static Pathfinder *create();
    
    void init();
    void findPath(int idBegin, int idEnd);
	void findWC(int idBegin);
    //CCArray *getArrayTiles();
    
    void execute();
    void start(int idBegin, int idEnd);
	void nextMap();
	void step(int nextValue, bool firstTime);
	void nextStep(bool firstTime);
	void previousStep(bool firstTime);
	void previousMap();
	CCString *getNextMapInfo();
	
	void loadMap(CCString *mapName, bool isVisible);
	void loadIcons();
    void executeAStar(bool smooth);
	void drawLines(LineType lineType);
	void drawAllLines();
	void showStepLine(bool firstTime);
	
	void releaseActualMap();
	void unlockStep(CCNode *sender);

	void nextMapInterval(CCNode *sender);
	void previousMapInterval(CCNode *sender);
	
    int getStep();
    int getTotalStep();
	
	void calculateTotalSteps();
	void nextStepCount(CCNode *sender);
	
	std::string descriptionStep;
	CCArray *getArrayIcons();
	
	int getStepsCount();
	int getStepActual();
	
private:
    //AStar *aStar;
    //CCArray *arrayTiles;
    CCArray *arrayMaps;
    CCArray *arrayMapNames;
	std::vector<int> mapBuildings;
	std::vector<int> mapFloors;
	
	std::vector<ASTile> arrayPoints;
	CCArray *arrayIcons;
	CCArray *arrayActualSteps;
	
	CCArray *arrayLines;
    
    int actualMapIndex;
	int actualStep;
	float angle;
	bool stepLock;
    //CCTMXTiledMap *actualMap;
   
	CCDictionary *plistWaypoints;
	
	int valueI;
	int stepsCount;
	int stepActual;

};

#endif
