#include <iostream>  // Incluye la biblioteca de entrada/salida est�ndar de C++.

#include "G4RunManager.hh"  // Incluye las declaraciones de la clase G4RunManager.
#include "G4UImanager.hh"   // Incluye las declaraciones de la clase G4UImanager.
#include "G4VisManager.hh"  // Incluye las declaraciones de la clase G4VisManager.
#include "G4VisExecutive.hh"  // Incluye las declaraciones de la clase G4VisExecutive.
#include "G4UIExecutive.hh"  // Incluye las declaraciones de la clase G4UIExecutive.

#include "construction.hh"  // Incluye el archivo de encabezado "construction.hh", que contiene la definici�n de la clase DetectorConstruction.

int main(int argc, char** argv)
{
    G4RunManager *runManager = new G4RunManager();  // Crea una instancia de G4RunManager.

    runManager->SetUserInitialization(new DetectorConstruction());  // Configura la construcci�n del detector en el G4RunManager.

    runManager->Initialize();  // Inicializa el G4RunManager.

    G4UIExecutive *ui = new G4UIExecutive(argc, argv);  // Crea una interfaz de usuario gr�fica para Geant4.

    G4VisManager *visManager = new G4VisExecutive();  // Crea una instancia de G4VisExecutive para la visualizaci�n.
    visManager->Initialize();  // Inicializa el sistema de visualizaci�n.

    G4UImanager *UImanager = G4UImanager::GetUIpointer();  // Obtiene un puntero al administrador de comandos de Geant4.

    ui->SessionStart();  // Inicia la sesi�n de usuario para interactuar con la simulaci�n.

    return 0;  // Devuelve 0 para indicar que el programa se ejecut� con �xito.
}
