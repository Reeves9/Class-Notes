//program to solve diamond problem
using System;

namespace DiamondProblem {
    /// <summary>
    /// Think of IVehicle as a basic blueprint for any vehicle
    /// Just like how all vehicles need to start somehow
    /// </summary>
    interface IVehicle {
        void Start();
    }

    /// <summary>
    /// ICar is like a car's manual
    /// It tells us what a car should do - start and drive
    /// </summary>
    interface ICar : IVehicle {
        new void Start();  // Cars have their own way of starting
        void Drive();      // Cars can drive on roads
    }

    /// <summary>
    /// IBoat is like a boat's manual
    /// It tells us what a boat should do - start and sail
    /// </summary>
    interface IBoat : IVehicle {
        new void Start();  // Boats have their own way of starting
        void Sail();       // Boats can sail on water
    }

    /// <summary>
    /// AmphibiousVehicle is like a Swiss Army knife - it can do multiple things
    /// It's both a car AND a boat (like those duck boats you see in tourist areas)
    /// This is where we solve the "diamond problem" by clearly stating how each type of 'Start' works
    /// </summary>
    class AmphibiousVehicle : ICar, IBoat {
        // When used as a car, start like this
        void ICar.Start() {
            Console.WriteLine("Car engine starting");
        }

        // When used as a boat, start like this
        void IBoat.Start() {
            Console.WriteLine("Boat engine starting");
        }

        // General way of starting (default behavior)
        public void Start() {
            Console.WriteLine("Vehicle starting in hybrid mode");
        }

        // Regular driving on land
        public void Drive() {
            Console.WriteLine("Driving on land");
        }

        // Regular sailing on water
        public void Sail() {
            Console.WriteLine("Sailing in water");
        }
    }

    /// <summary>
    /// This is where we test everything
    /// Think of it as taking our Swiss Army knife vehicle for a test run
    /// </summary>
    class Program {
        static void Main(string[] args) {
            // Create our special vehicle that works on both land and water
            AmphibiousVehicle vehicle = new AmphibiousVehicle();
            
            // Start it normally
            vehicle.Start();  // Uses the default start method

            // Start it specifically as a car
            ((ICar)vehicle).Start();  // Uses car's start method

            // Start it specifically as a boat
            ((IBoat)vehicle).Start(); // Uses boat's start method

            // Try out the land mode
            vehicle.Drive();

            // Try out the water mode
            vehicle.Sail();
        }
    }
}
