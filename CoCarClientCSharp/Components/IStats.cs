namespace Components
{
    using System.Runtime.InteropServices;

    // {32B468EE-093D-43C1-AC43-96FBC78297AA}
    // DEFINE_GUID(IID_IStats ,
    // 0x32b468ee, 0x93d, 0x43c1, 0xac, 0x43, 0x96, 0xfb, 0xc7, 0x82, 0x97, 0xaa);

    [ComImport, InterfaceType(ComInterfaceType.InterfaceIsIUnknown), Guid("32B468EE-093D-43C1-AC43-96FBC78297AA")]
    public interface IStats
    {
        void DisplayStats();
        void GetCarName(ref string carName);
    }
}