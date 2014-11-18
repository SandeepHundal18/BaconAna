#ifndef BACONANA_DATAFORMATS_TPHOTON_HH
#define BACONANA_DATAFORMATS_TPHOTON_HH

#include "BaconAna/DataFormats/interface/BaconAnaDefs.hh"
#include <TObject.h>

namespace baconhep
{
  class TPhoton : public TObject
  {
    public:
      TPhoton():
      pt(0), eta(0), phi(0),ptcorr(0),ptunc(0),
      scEt(0), scEta(0), scPhi(0), r9(0),
      pfPt(0), pfEta(0), pfPhi(0),
      trkIso04(-1), ecalIso04(-1), hcalIso04(-1),
      chHadIso03(-1), gammaIso03(-1), neuHadIso03(-1),
      isoForFsr03(-1), mvaNothingGamma(0),mva(0),
      hovere(0), sthovere(0), sieie(0), sipip(0),
      fiducialBits(0),
      typeBits(0),
      scID(-1),
      hasPixelSeed(false), isConv(false),
      hltMatchBits(0)
      {}
      ~TPhoton(){}
    
      float         pt, eta, phi,ptcorr,ptunc;                         // kinematics
      float         scEt, scEta, scPhi, r9;               // SuperCluster kinematics
      float         pfPt, pfEta, pfPhi;                   // matching PF-candidate kinematics
      float         trkIso04, ecalIso04, hcalIso04;       // detector isolation
      float         chHadIso03, gammaIso03, neuHadIso03;  // PF isolation variables
      float         chHadIso03SelVtx,chHadIso03WstVtx;    // Isolation from the PV vs worst vertex Iso
      float         isoForFsr03;                          // PF-based isolation for HZZ4l FSR recovery
      float         mvaNothingGamma;                      // PF MVA for gamma detection
      float         mva;                                  // H=>gg Photon MVA
      float         hovere;                               // H/E
      float         sthovere;                             // Single tower H/E (https://twiki.cern.ch/twiki/bin/viewauth/CMS/HoverE2012)
      float         sieie, sipip;                         // shower shape
      unsigned int  fiducialBits;                         // ECAL fiducial region
      unsigned int  typeBits;                             // photon type
      int           scID;                                 // supercluster ID (unique per event)
      bool          hasPixelSeed;                         // has pixel seed?
      bool          passElectronVeto;                     // if false, its not a photon
      bool          isConv;                               
      TriggerObjects hltMatchBits;                         // HLT matches
          
    ClassDef(TPhoton,1)
  };
  
  enum EPhotonType
  {
    kEGamma       = 1,
    kPFPhoton     = 2,
    kPFMuonPhoton = 4   // for HZZ4l FSR recovery
  };
}
#endif
