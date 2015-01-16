#ifndef SHPPROC_H
#define SHPPROC_H


class ShpProc
{
    public:
        ShpProc();
        virtual ~ShpProc();
        void ChangeType();
        void AutoselectType();
        void InsertFrame();
        void DeleteFrame();
        void PrevFrame();
        void NextFrame();
        void SplitFrames();
        void LoadPalette();
        void LoadCustomPalette();
        void LoadTDPalette();
        void LoadRAPalette();
        void LoadTSPalette();
        void LoadRA2Palette();
        void LoadYuriPalette();
        void UpdatePalettes();
        void ChangeColourSchemeSettings();
        void ApplyColourScheme();
        void UpdateColourSchemes();
        void Sequence();
        void AutoShadows();
        void ConvertShadows();
        void FixShadows();
        void GenerateCameo();
    protected:
    private:
};

#endif // SHPPROC_H
