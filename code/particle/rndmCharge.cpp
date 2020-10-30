int rndmCharge(int const& rndm) {
  int charge;

  if(rndm % 2 == 0) {
    charge = 1;
  } else {
    charge = -1;
  }

  return charge;
}