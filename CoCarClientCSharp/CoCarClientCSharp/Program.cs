namespace CoCarClientCSharp
{
    using System;
    using Components;

    class Program
    {
        static void Main()
        {
            Car myCar = new Car();

            ICreateCar iCreateCar = (ICreateCar)myCar;
            IStats iStats = (IStats)myCar;

            // Set car name
            Console.WriteLine("Напишите имя: ");
            iCreateCar.SetCarName(Console.ReadLine());

            // Get car name
            string carName = string.Empty;
            iStats.GetCarName(carName);
            Console.WriteLine(carName);
        }
    }
}
