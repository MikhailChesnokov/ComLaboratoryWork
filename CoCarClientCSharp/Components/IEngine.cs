namespace Components
{
    using System.Runtime.InteropServices;

    // {E0D20966-0AF5-40FA-9AC2-BE8CFEE0BB6E}
    // DEFINE_GUID(IID_IEngine ,
    // 0xe0d20966, 0xaf5, 0x40fa, 0x9a, 0xc2, 0xbe, 0x8c, 0xfe, 0xe0, 0xbb, 0x6e);

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("E0D20966-0AF5-40FA-9AC2-BE8CFEE0BB6E")]
    public interface IEngine
    {
        void SpeedUp();
        void GetMaxSpeed(ref int maxSpeed);
        void GetCurSpeed(ref int curSpeed);
    }
}