namespace Components
{
    using System.Runtime.InteropServices;

    // {C07EA3F5-01E4-4815-89B8-0EE4DECADF19}
    // DEFINE_GUID(IID_ICreateCar ,
    // 0xc07ea3f5, 0x1e4, 0x4815, 0x89, 0xb8, 0xe, 0xe4, 0xde, 0xca, 0xdf, 0x19);

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("C07EA3F5-01E4-4815-89B8-0EE4DECADF19")]
    public interface ICreateCar
    {
        void SetCarName(string carName);
        void SetMaxSpeed(int maxSpeed);
    }
}