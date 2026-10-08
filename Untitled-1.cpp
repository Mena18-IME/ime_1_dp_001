#include <iostream>
#include <string>
#include <vector>
#include "Robot.h"
#include "Integrante.h"
#include "Equipo.h"
#include "Competencia.h"
#include "Enfrentamiento.h"

// ---------------------------------------------------------------------
// Tema 6: captura de un Equipo completo por consola
// Flujo: nombre del equipo -> numero de integrantes -> cada integrante
//        -> numero de robots -> cada robot
// ---------------------------------------------------------------------
Equipo capturarEquipo() {
    std::string nombreEquipo;
    std::cout << "Nombre del equipo: ";
    std::getline(std::cin, nombreEquipo);

    Equipo equipo(nombreEquipo);

    int numIntegrantes = 0;
    std::cout << "Numero de integrantes: ";
    std::cin >> numIntegrantes;
    std::cin.ignore(); // limpiar el salto de linea pendiente antes de usar getline

    for (int i = 0; i < numIntegrantes; ++i) {
        std::string nombre, rol;
        std::cout << "  Integrante " << (i + 1) << " - nombre: ";
        std::getline(std::cin, nombre);
        std::cout << "  Integrante " << (i + 1) << " - rol (Analista/Programador/Tester/...): ";
        std::getline(std::cin, rol);
        equipo.agregarIntegrante(Integrante(nombre, rol));
    }

    int numRobots = 0;
    std::cout << "Numero de robots: ";
    std::cin >> numRobots;
    std::cin.ignore();

    for (int i = 0; i < numRobots; ++i) {
        std::string nombre, tipo;
        std::cout << "  Robot " << (i + 1) << " - nombre: ";
        std::getline(std::cin, nombre);
        std::cout << "  Robot " << (i + 1) << " - tipo (Sumo/Seguidor de linea/Combate/...): ";
        std::getline(std::cin, tipo);
        equipo.agregarRobot(Robot(nombre, tipo));
    }

    return equipo;
}

// ---------------------------------------------------------------------
// Tema 5: datos de ejemplo para practicar vector<Robot> y filtrado
// ---------------------------------------------------------------------
std::vector<Robot> robotsDeEjemplo() {
    return {
        Robot("Titan",     "Sumo"),
        Robot("Rayo",      "Seguidor de linea"),
        Robot("Coloso",    "Sumo"),
        Robot("Vortex",    "Combate"),
        Robot("Centella",  "Seguidor de linea")
    };
}

int main() {
    Competencia competencia;
    Enfrentamiento enfrentamiento;

    std::cout << "=== Demo POO - Parcial 1: Sistema de gestion de competencia de robotica ===\n";
    std::cout << "(Este programa cubre: captura por consola, vector<Robot>, filtrado y batalla aleatoria)\n";

    // --- Tema 5: cargar y filtrar por tipo ---
    std::vector<Robot> robots = robotsDeEjemplo();
    std::cout << "\n--- Robots de ejemplo cargados (" << robots.size() << ") ---\n";
    for (const auto& r : robots) {
        std::cout << "  " << r.getNombre() << " [" << r.getTipo() << "]\n";
    }

    std::string tipoBuscado = "Sumo";
    std::vector<Robot> filtrados = competencia.filtrarPorTipo(robots, tipoBuscado);
    std::cout << "\n--- Robots filtrados por tipo '" << tipoBuscado << "' (" << filtrados.size() << ") ---\n";
    for (const auto& r : filtrados) {
        std::cout << "  " << r.getNombre() << "\n";
    }

    // --- Tema 7: simular una batalla aleatoria entre los robots de ejemplo ---
    std::cout << "\n--- Simulacion de batalla (2 robots al azar, ganador al azar) ---\n";
    int idxGanador = enfrentamiento.simularBatalla(filtrados);
    std::cout << "Robot ganador: " << filtrados[idxGanador].getNombre()
              << " [" << filtrados[idxGanador].getTipo() << "]\n";

    // --- Tema 6 y 9: mini-reto integrador ---
    // Descomenta este bloque para practicar en clase la captura interactiva
    // completa de un Equipo (Tema 6) y luego correr una batalla con SUS
    // propios robots capturados (Tema 9 - mini-reto integrador).
    //
    // Recordatorio: esto NO es la solucion del parcial. Falta el resto
    // del diseno (Competencia, Disciplinas, manejo de robot sin rival, etc.)
    // que cada equipo debe identificar y construir.
    /*
    std::cout << "\n=== Mini-reto integrador: captura tu propio equipo ===\n";
    Equipo miEquipo = capturarEquipo();
    miEquipo.mostrarResumen();

    if (miEquipo.getRobots().size() >= 2) {
        int idx = enfrentamiento.simularBatalla(miEquipo.getRobots());
        std::cout << "\nGanador de la batalla de ejemplo: "
                  << miEquipo.getRobots()[idx].getNombre() << "\n";
    } else {
        std::cout << "\nSe necesitan al menos 2 robots en el equipo para simular una batalla.\n";
    }
    */

    return 0;
}