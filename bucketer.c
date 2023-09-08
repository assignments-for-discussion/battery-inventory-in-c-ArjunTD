#include <stdio.h>
#include <assert.h>

struct CountsBySoH {
  int healthy;
  int exchange;
  int failed;
};

struct CountsBySoH countBatteriesByHealth(const int* presentCapacities, int nBatteries) {
  struct CountsBySoH counts = {0, 0, 0};
  
  
  int rc = 120; 
  
  for (int i = 0; i < nBatteries; i++) {
   
    float sohp = ((float)presentCapacities[i] / rc) * 100; //caluclating SOH Values
    if (sohp > 80) {
      counts.healthy++;  //Falls under healthy category
    } else if (sohp >= 65 && sohp <= 80) {
      counts.exchange++; //Falls under exchange category
    } else {
      counts.failed++;   //Falls under failed category
    }
  }
  
  return counts; //returns structure counts which has count values of the categories
}

void testBucketingByHealth() {
  const int presentCapacities[] = {115, 118, 80, 95, 91, 77};
  const int numberOfBatteries = sizeof(presentCapacities) / sizeof(presentCapacities[0]);
  printf("Counting batteries by SoH...\n");
  struct CountsBySoH counts = countBatteriesByHealth(presentCapacities, numberOfBatteries);
  assert(counts.healthy == 2);  //verifies that the above code returns 2 for healty category
  assert(counts.exchange == 3); //verifies that the above code returns 3 for exchange category
  assert(counts.failed == 1);  //verifies that the above code returns 1 for failed category
  printf("Done counting :)\n"); // If all the above assertions are true then Done counting is printed successfully
}

int main() {
  testBucketingByHealth();
  return 0;
}
