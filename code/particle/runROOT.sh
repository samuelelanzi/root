root -l <<EOF
gROOT->LoadMacro("ParticleType.cpp+")
gROOT->LoadMacro("ResonanceType.cpp+")
gROOT->LoadMacro("Particle.cpp+")
gROOT->LoadMacro("main.cpp+")
gROOT->LoadMacro("rndmCharge.cpp+")
gROOT->LoadMacro("invMass.cpp+")
EOF
root -l
