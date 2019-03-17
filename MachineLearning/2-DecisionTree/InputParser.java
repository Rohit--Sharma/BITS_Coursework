import java.awt.*;
import java.io.*;
import java.util.*; 
import java.util.List;

enum Workclass {
	Private(0), 
	Self_emp_not_inc(1), 
	Self_emp_inc(2), 
	Federal_gov(3), 
	Local_gov(4), 
	State_gov(5), 
	Without_pay(6), 
	Never_worked(7);		//null for unknown
		
	private final int value;
	public static final int nValues = 8;
	private Workclass(final int newValue) {
        value = newValue;
    }

    public int getValue() { 
		return value; 
	}
}

enum Education {
	Bachelors(0), 
	Some_college(1), 
	n11th(2), 				//prefixed with n for numbers
	HS_grad(3), 
	Prof_school(4), 
	Assoc_acdm(5), 
	Assoc_voc(6), 
	n9th(7), 
	n7th_8th(8), 
	n12th(9), 
	Masters(10), 
	n1st_4th(11), 
	n10th(12), 
	Doctorate(13), 
	n5th_6th(14), 
	Preschool(15);
		
	public static final int nValues = 16;
	private final int value;
	
	private Education (final int newValue) {
            value = newValue;
    }

    public int getValue() { 
		return value; 
	}
}

enum MaritalStatus {
	Married_civ_spouse(0), 
	Divorced(1), 
	Never_married(2), 
	Separated(3), 
	Widowed(4), 
	Married_spouse_absent(5), 
	Married_AF_spouse(6);
		
	public static final int nValues = 7;
	private final int value;
	
	private MaritalStatus (final int newValue) {
            value = newValue;
    }

    public int getValue() { 
		return value; 
	}
}

enum Occupation {
	Tech_support(0), 
	Craft_repair(1), 
	Other_service(2), 
	Sales(3), 
	Exec_managerial(4), 
	Prof_specialty(5), 
	Handlers_cleaners(6), 
	Machine_op_inspct(7), 
	Adm_clerical(8), 
	Farming_fishing(9), 
	Transport_moving(10), 
	Priv_house_serv(11), 
	Protective_serv(12), 
	Armed_Forces(13);
		
	public static final int nValues = 14;
	private final int value;
	
	private Occupation (final int newValue) {
            value = newValue;
    }

    public int getValue() { 
		return value; 
	}
}

enum Relationship {
	Wife(0), 
	Own_child(1), 
	Husband(2), 
	Not_in_family(3), 
	Other_relative(4), 
	Unmarried(5);
		
	public static final int nValues = 6;
	private final int value;
	
	private Relationship (final int newValue) {
            value = newValue;
    }

    public int getValue() { 
		return value; 
	}
}

enum Race {
	White(0), 
	Asian_Pac_Islander(1), 
	Amer_Indian_Eskimo(2), 
	Other(3), 
	Black(4);
		
	public static final int nValues = 5;
	private final int value;
	
	private Race (final int newValue) {
            value = newValue;
    }

    public int getValue() { 
		return value; 
	}
}

enum Sex {
	Female(0),
	Male(1);
		
	public static final int nValues = 2;
	private final int value;
	
	private Sex (final int newValue) {
            value = newValue;
    }

    public int getValue() { 
		return value; 
	}
}

enum NativeCountry {
	United_States(0), 
	Cambodia(1), 
	England(2), 
	Puerto_Rico(3), 
	Canada(4), 
	Germany(5), 
	Outlying_US_Guam_USVI_etc_(6), 
	India(7), 
	Japan(8), 
	Greece(9), 
	South(10), 
	China(11), 
	Cuba(12), 
	Iran(13), 
	Honduras(14), 
	Philippines(15), 
	Italy(16), 
	Poland(17), 
	Jamaica(18), 
	Vietnam(19), 
	Mexico(20), 
	Portugal(21), 
	Ireland(22), 
	France(23), 
	Dominican_Republic(24), 
	Laos(25), 
	Ecuador(26), 
	Taiwan(27), 
	Haiti(28), 
	Columbia(29), 
	Hungary(30), 
	Guatemala(31), 
	Nicaragua(32), 
	Scotland(33), 
	Thailand(34), 
	Yugoslavia(35), 
	El_Salvador(36), 
	Trinadad_Tobago(37), 
	Peru(38), 
	Hong(39), 
	Holand_Netherlands(40);
		
	public static final int nValues = 41;
	private final int value;
	
	private NativeCountry (final int newValue) {
            value = newValue;
    }

    public int getValue() { 
		return value; 
	}
}

enum Classification {
	GreaterThan(0),
	LessThanEqual(1);
		
	public static final int nValues = 2;
	private final int value;
	
	private Classification (final int newValue) {
            value = newValue;
    }

    public int getValue() { 
		return value; 
	}
}

class Attribute 
{
	int age;
	Workclass wClass;
	int fnlwgt;
	Education education;
	int educationNum;
	MaritalStatus marStatus;
	Occupation occupation;
	Relationship relationship;
	Race race;
	Sex sex;
	int capitalGain;
	int capitalLoss;
	int hoursPerWeek;
	NativeCountry nativeCountry;
	Classification classification;
}

class InputParser
{
	public static final int SIZE = 32561;
	
	private static double entropy(Attribute []sample) {
		int greaterThan = 0, lessThan = 0;
		for (int i=0; i<sample.length; i++) {
			if (sample[i].classification == Classification.GreaterThan)
				greaterThan++;
			else
				lessThan++;
		}
		//System.out.println(greaterThan + " " + lessThan);
		double p1 = (double)greaterThan/(greaterThan + lessThan), p2 = (double)lessThan/(greaterThan + lessThan);
		//System.out.println(p1 + " " + p2);
		return -p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2);
	}
	
	private static void discretisingContinousValues(int attr, Attribute data[]) {
		switch(attr) {
			case 1: {					//Age
				int mean = 0;
				for(int i=0; i<SIZE; i++) {
					mean += data[i].age;
				}
				mean /= SIZE;
				for(int i=0; i<SIZE; i++) {
					if(data[i].age <= mean)
						data[i].age = 0;		//LOW
					else
						data[i].age = 1;		//High
				}
			} case 3: {					//fnlwgt
				int mean = 0;
				for(int i=0; i<SIZE; i++) {
					mean += data[i].fnlwgt;
				}
				mean /= SIZE;
				for(int i=0; i<SIZE; i++) {
					if(data[i].fnlwgt <= mean)
						data[i].fnlwgt = 0;		//LOW
					else
						data[i].fnlwgt = 1;		//High
				}
			} case 5: {					//Education-num
				int mean = 0;
				for(int i=0; i<SIZE; i++) {
					mean += data[i].educationNum;
				}
				mean /= SIZE;
				for(int i=0; i<SIZE; i++) {
					if(data[i].educationNum <= mean)
						data[i].educationNum = 0;		//LOW
					else
						data[i].educationNum = 1;		//High
				}
			} case 11: {				//capital-gain
				int mean = 0;
				for(int i=0; i<SIZE; i++) {
					mean += data[i].capitalGain;
				}
				mean /= SIZE;
				for(int i=0; i<SIZE; i++) {
					if(data[i].capitalGain <= mean)
						data[i].capitalGain = 0;		//LOW
					else
						data[i].capitalGain = 1;		//High
				}
			} case 12: {				//capital-loss
				int mean = 0;
				for(int i=0; i<SIZE; i++) {
					mean += data[i].capitalLoss;
				}
				mean /= SIZE;
				for(int i=0; i<SIZE; i++) {
					if(data[i].capitalLoss <= mean)
						data[i].capitalLoss = 0;		//LOW
					else
						data[i].capitalLoss = 1;		//High
				}
			} case 13: {				//Hoursperweek
				int mean = 0;
				for(int i=0; i<SIZE; i++) {
					mean += data[i].hoursPerWeek;
				}
				mean /= SIZE;
				for(int i=0; i<SIZE; i++) {
					if(data[i].hoursPerWeek <= mean)
						data[i].hoursPerWeek = 0;		//LOW
					else
						data[i].hoursPerWeek = 1;		//High
				}
			}
		}
	}
	
	private static void fillMissingValues(int attr, Attribute data[]) {
		
		/*switch(attr) {
			case 1: {					//Age
				int freq[] = new int[Age.nValues];
				for(int i=0; i<SIZE; i++) {
					if(data[i].age != null)
						freq[data[i].age.getValue()]++;
				}
				int max = 0, idx = -1; 
				for(int i=0; i<Age.nValues; i++) {
					if(freq[i] > max) {
						max = freq[i];
						idx = i;
					}
				}
				for(int i=0; i<SIZE; i++) {
					if(data[i].age == null)
						data[i].age = idx;
				}
			} case 3: {					//fnlwgt
				
			} case 5: {					//Education-num
				
			} case 11: {				//capital-gain
				
			} case 12: {				//capital-loss
				
			} case 13: {				//Hoursperweek
				
			}
		}*/
	}
	
	private static double informationGain(Attribute []sample, int attr)
	{
		double ent = entropy(sample), weightedEntropyOfValues = 0;
		//int numExOfAttVal = 0;
		switch(attr) {
			case 1:	{					//Age
				int arr[][] = new int[2][3];
				for (int i=0; i<sample.length; i++) {
					  try {
						arr[sample[i].age][0]++;
						if(sample[i].classification == Classification.GreaterThan)
							arr[sample[i].age][1]++;
						else
							arr[sample[i].age][2]++;
					  } catch(Exception e) {
						e.printStackTrace();
				      }
				}
				double p1, p2;
				for	(int i=0; i<2; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			} case 2: {					//Workclass
				
				int arr[][] = new int[Workclass.nValues][3];
				for (int i=0; i<sample.length; i++) {
					if (sample[i].wClass != null) { // 
					   try {
							//System.out.println("i: " + i + ", Index: " + sample[i].wClass.getValue());
							arr[sample[i].wClass.getValue()][0]++;
							if(sample[i].classification == Classification.GreaterThan)
								arr[sample[i].wClass.getValue()][1]++;
							else
								arr[sample[i].wClass.getValue()][2]++;
					   } catch(Exception e) {
							e.printStackTrace();
					   }
					}
				}
				double p1, p2;
				for	(int i=0; i<Workclass.nValues; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
					//System.out.println("	nValues: " + arr[i][0] + ", nGreater: " + arr[i][1] + ", nLess: " + arr[i][2]);
				}
				break;
				
			} case 3: {					//fnlwgt
				int arr[][] = new int[2][3];
				for (int i=0; i<sample.length; i++) {
					  try {
						arr[sample[i].fnlwgt][0]++;
						if(sample[i].classification == Classification.GreaterThan)
							arr[sample[i].fnlwgt][1]++;
						else
							arr[sample[i].age][2]++;
					  } catch(Exception e) {
						e.printStackTrace();
				      }
				}
				double p1, p2;
				for	(int i=0; i<2; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			} case 4: {					//Education
				int arr[][] = new int[Education.nValues][3];
				for (int i=0; i<sample.length; i++) {
					if (sample[i].education != null) { // 
					   try {
							arr[sample[i].education.getValue()][0]++;
							if(sample[i].classification == Classification.GreaterThan)
								arr[sample[i].education.getValue()][1]++;
							else
								arr[sample[i].education.getValue()][2]++;
					   } catch(Exception e) {
							e.printStackTrace();
					   }
					}
				}
				double p1, p2;
				for	(int i=0; i<Education.nValues; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			} case 5: {					//Education-num
				int arr[][] = new int[2][3];
				for (int i=0; i<sample.length; i++) {
					  try {
						arr[sample[i].educationNum][0]++;
						if(sample[i].classification == Classification.GreaterThan)
							arr[sample[i].educationNum][1]++;
						else
							arr[sample[i].educationNum][2]++;
					  } catch(Exception e) {
						e.printStackTrace();
				      }
				}
				double p1, p2;
				for	(int i=0; i<2; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			} case 6: {					//Marital status
				int arr[][] = new int[MaritalStatus.nValues][3];
				for (int i=0; i<sample.length; i++) {
					if (sample[i].marStatus != null) { // 
					   try {
							arr[sample[i].marStatus.getValue()][0]++;
							if(sample[i].classification == Classification.GreaterThan)
								arr[sample[i].marStatus.getValue()][1]++;
							else
								arr[sample[i].marStatus.getValue()][2]++;
					   } catch(Exception e) {
							e.printStackTrace();
					   }
					}
				}
				double p1, p2;
				for	(int i=0; i<MaritalStatus.nValues; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			} case 7: {					//Occupation
				int arr[][] = new int[Occupation.nValues][3];
				for (int i=0; i<sample.length; i++) {
					if (sample[i].occupation != null) { // 
					   try {
							arr[sample[i].occupation.getValue()][0]++;
							if(sample[i].classification == Classification.GreaterThan)
								arr[sample[i].occupation.getValue()][1]++;
							else
								arr[sample[i].occupation.getValue()][2]++;
					   } catch(Exception e) {
							e.printStackTrace();
					   }
					}
				}
				double p1, p2;
				for	(int i=0; i<Occupation.nValues; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			} case 8: {					//Relationship
				int arr[][] = new int[Relationship.nValues][3];
				for (int i=0; i<sample.length; i++) {
					if (sample[i].relationship != null) { // 
					   try {
							arr[sample[i].relationship.getValue()][0]++;
							if(sample[i].classification == Classification.GreaterThan)
								arr[sample[i].relationship.getValue()][1]++;
							else
								arr[sample[i].relationship.getValue()][2]++;
					   } catch(Exception e) {
							e.printStackTrace();
					   }
					}
				}
				double p1, p2;
				for	(int i=0; i<Relationship.nValues; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			} case 9: {					//Race
				int arr[][] = new int[Race.nValues][3];
				for (int i=0; i<sample.length; i++) {
					if (sample[i].race != null) { // 
					   try {
							arr[sample[i].race.getValue()][0]++;
							if(sample[i].classification == Classification.GreaterThan)
								arr[sample[i].race.getValue()][1]++;
							else
								arr[sample[i].race.getValue()][2]++;
					   } catch(Exception e) {
							e.printStackTrace();
					   }
					}
				}
				double p1, p2;
				for	(int i=0; i<Race.nValues; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			} case 10: {				//Sex
				int arr[][] = new int[Sex.nValues][3];
				for (int i=0; i<sample.length; i++) {
					if (sample[i].sex != null) { // 
					   try {
							arr[sample[i].sex.getValue()][0]++;
							if(sample[i].classification == Classification.GreaterThan)
								arr[sample[i].sex.getValue()][1]++;
							else
								arr[sample[i].sex.getValue()][2]++;
					   } catch(Exception e) {
							e.printStackTrace();
					   }
					}
				}
				double p1, p2;
				for	(int i=0; i<Sex.nValues; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			} case 11: {				//capital-gain
				int arr[][] = new int[2][3];
				for (int i=0; i<sample.length; i++) {
					  try {
						arr[sample[i].capitalGain][0]++;
						if(sample[i].classification == Classification.GreaterThan)
							arr[sample[i].capitalGain][1]++;
						else
							arr[sample[i].capitalGain][2]++;
					  } catch(Exception e) {
						e.printStackTrace();
				      }
				}
				double p1, p2;
				for	(int i=0; i<2; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			} case 12: {				//capital-loss
				int arr[][] = new int[2][3];
				for (int i=0; i<sample.length; i++) {
					  try {
						arr[sample[i].capitalLoss][0]++;
						if(sample[i].classification == Classification.GreaterThan)
							arr[sample[i].capitalGain][1]++;
						else
							arr[sample[i].capitalGain][2]++;
					  } catch(Exception e) {
						e.printStackTrace();
				      }
				}
				double p1, p2;
				for	(int i=0; i<2; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			} case 13: {				//Hoursperweek
				int arr[][] = new int[2][3];
				for (int i=0; i<sample.length; i++) {
					  try {
						arr[sample[i].hoursPerWeek][0]++;
						if(sample[i].classification == Classification.GreaterThan)
							arr[sample[i].hoursPerWeek][1]++;
						else
							arr[sample[i].hoursPerWeek][2]++;
					  } catch(Exception e) {
						e.printStackTrace();
				      }
				}
				double p1, p2;
				for	(int i=0; i<2; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			} case 14: {				//COuntry
				int arr[][] = new int[NativeCountry.nValues][3];
				for (int i=0; i<sample.length; i++) {
					if (sample[i].nativeCountry != null) { // 
					   try {
							arr[sample[i].nativeCountry.getValue()][0]++;
							if(sample[i].classification == Classification.GreaterThan)
								arr[sample[i].nativeCountry.getValue()][1]++;
							else
								arr[sample[i].nativeCountry.getValue()][2]++;
					   } catch(Exception e) {
							e.printStackTrace();
					   }
					}
				}
				double p1, p2;
				for	(int i=0; i<NativeCountry.nValues; i++) {
					if(arr[i][0] != 0) {
						try {
							p1 = (double)arr[i][1] / arr[i][0]; 
							p2 = (double)arr[i][2] / arr[i][0];
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				break;
			}
		}
		return ent - weightedEntropyOfValues;
	}
	
	private static int decisionAttribute(Attribute []node, int []attributes) {
		double max = -1;
		int maxIdx = -1;
		for(int i=0; i<14; i++) {
			if(max > informationGain(node, i+1)) {
				max = informationGain(node, i+1);
				maxIdx = i+1;
			}
		}
		return maxIdx;
	}
	
	public static Tree<Integer> buildDecisionTree(Attribute []node, int []attributes)
	{
		//System.out.println(informationGain(node, 2));
		Tree<Integer> root = new Tree<Integer>(-1);
		
		int nPos = 0;							// nPos = number of positive examples
		for (Attribute ex : node) {
			if(ex.classification == Classification.GreaterThan)
				nPos++;							
		}
		if(nPos == node.length) {				// If all examples are positive
			root.clf = true;					//		return single node tree, 'root' with clf = +
		} else if(nPos == 0) {					// If all examples are negative
			root.clf = false;					//		return single node tree, 'root' with clf = -
		} else if(attributes.length == 0) {		// If attributes is empty
			if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
				root.clf = true;
			else
				root.clf = false;
		} else {
			
			int bestAttribute = decisionAttribute(node, attributes);	
			
			//Tree<Integer> child;
			for (int i=0; i<Workclass.nValues; i++) {
				//child = new Tree<Integer>(i);	// child for ith attribute
				root.addChild(i);
				int count = 0, k=0;
				for (int j=0; j<node.length; j++) 
					if(node[j].wClass != null && node[j].wClass.getValue() == i)
						count++;
				Attribute []subsetExamplesVi = new Attribute[count];
				// initialise subsetExamplesVi
				for (int j=0; j<node.length; j++) 
					if(node[j].wClass != null && node[j].wClass.getValue() == i)
						subsetExamplesVi[k++] = node[j];
					
				if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
					
				} else {
					//buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
				}
			}
		}
		
		return root;
	}
	
	public static void main(String ...args) throws IOException
	{
		FileReader in = null;
		
		Attribute data[] = new Attribute[SIZE];
		
		//Read the entire file into a String
		String file = new Scanner(new File("census-income.data.txt")).useDelimiter("\\Z").next(), temp;
		
		int strtIndex = 0, endIndex, i = SIZE;
		//ReadInput into arrays
		while(i-- != 0) {	
			
			data[SIZE-i-1] = new Attribute();
			
			//Age
			endIndex = file.indexOf(',', strtIndex);
			data[SIZE-i-1].age = Integer.parseInt(file.substring(strtIndex, endIndex));
			strtIndex = endIndex + 1;		//Index of space
			
			//Workclass
			endIndex = file.indexOf(',', strtIndex);
			temp = file.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "Private": 
					data[SIZE-i-1].wClass = Workclass.Private; break;
				case "Self-emp-not-inc": 
					data[SIZE-i-1].wClass = Workclass.Self_emp_not_inc; break;
				case "Self-emp-inc": 
					data[SIZE-i-1].wClass = Workclass.Self_emp_inc; break;
				case "Federal-gov": 
					data[SIZE-i-1].wClass = Workclass.Federal_gov; break;
				case "Local-gov": 
					data[SIZE-i-1].wClass = Workclass.Local_gov; break;
				case "State-gov": 
					data[SIZE-i-1].wClass = Workclass.State_gov; break;
				case "Without-pay": 
					data[SIZE-i-1].wClass = Workclass.Without_pay; break;
				case "Never-worked": 
					data[SIZE-i-1].wClass = Workclass.Never_worked; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//FNLWGT
			endIndex = file.indexOf(',', strtIndex);
			data[SIZE-i-1].fnlwgt = Integer.parseInt(file.substring(strtIndex+1, endIndex));
			strtIndex = endIndex + 1;		//Index of space
			
			//Education
			endIndex = file.indexOf(',', strtIndex);
			temp = file.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "Bachelors": 
					data[SIZE-i-1].education = Education.Bachelors; break;
				case "Some-college": 
					data[SIZE-i-1].education = Education.Some_college; break;
				case "11th": 
					data[SIZE-i-1].education = Education.n11th; break;
				case "HS-grad": 
					data[SIZE-i-1].education = Education.HS_grad; break;
				case "Prof-school": 
					data[SIZE-i-1].education = Education.Prof_school; break;
				case "Assoc-acdm": 
					data[SIZE-i-1].education = Education.Assoc_acdm; break;
				case "Assoc-voc": 
					data[SIZE-i-1].education = Education.Assoc_voc; break;
				case "9th": 
					data[SIZE-i-1].education = Education.n9th; break;
				case "7th-8th": 
					data[SIZE-i-1].education = Education.n7th_8th; break;
				case "12th": 
					data[SIZE-i-1].education = Education.n12th; break;
				case "Masters": 
					data[SIZE-i-1].education = Education.Masters; break;
				case "1st-4th": 
					data[SIZE-i-1].education = Education.n1st_4th; break;
				case "10th": 
					data[SIZE-i-1].education = Education.n10th; break;
				case "Doctorate": 
					data[SIZE-i-1].education = Education.Doctorate; break;
				case "5th-6th": 
					data[SIZE-i-1].education = Education.n5th_6th; break;
				case "Preschool": 
					data[SIZE-i-1].education = Education.Preschool; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//eduNum
			endIndex = file.indexOf(',', strtIndex);
			data[SIZE-i-1].educationNum = Integer.parseInt(file.substring(strtIndex+1, endIndex));
			strtIndex = endIndex + 1;		//Index of space
			
			//Marital Status
			endIndex = file.indexOf(',', strtIndex);
			temp = file.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "Married-civ-spouse": 
					data[SIZE-i-1].marStatus = MaritalStatus.Married_civ_spouse; break;
				case "Divorced": 
					data[SIZE-i-1].marStatus = MaritalStatus.Divorced; break;
				case "Never-married": 
					data[SIZE-i-1].marStatus = MaritalStatus.Never_married; break;
				case "Separated": 
					data[SIZE-i-1].marStatus = MaritalStatus.Separated; break;
				case "Widowed": 
					data[SIZE-i-1].marStatus = MaritalStatus.Widowed; break;
				case "Married-spouse-absent": 
					data[SIZE-i-1].marStatus = MaritalStatus.Married_spouse_absent; break;
				case "Married-AF-spouse": 
					data[SIZE-i-1].marStatus = MaritalStatus.Married_AF_spouse; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//Occupation
			endIndex = file.indexOf(',', strtIndex);
			temp = file.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "Tech-support": 
					data[SIZE-i-1].occupation = Occupation.Tech_support; break;
				case "Craft-repair": 
					data[SIZE-i-1].occupation = Occupation.Craft_repair; break;
				case "Other-service": 
					data[SIZE-i-1].occupation = Occupation.Other_service; break;
				case "Sales": 
					data[SIZE-i-1].occupation = Occupation.Sales; break;
				case "Exec-managerial": 
					data[SIZE-i-1].occupation = Occupation.Exec_managerial; break;
				case "Prof-specialty": 
					data[SIZE-i-1].occupation = Occupation.Prof_specialty; break;
				case "Handlers-cleaners": 
					data[SIZE-i-1].occupation = Occupation.Handlers_cleaners; break;
				case "Machine-op-inspct": 
					data[SIZE-i-1].occupation = Occupation.Machine_op_inspct; break;
				case "Adm-clerical": 
					data[SIZE-i-1].occupation = Occupation.Adm_clerical; break;
				case "Farming-fishing": 
					data[SIZE-i-1].occupation = Occupation.Farming_fishing; break;
				case "Transport-moving": 
					data[SIZE-i-1].occupation = Occupation.Transport_moving; break;
				case "Priv-house-serv": 
					data[SIZE-i-1].occupation = Occupation.Priv_house_serv; break;
				case "Protective-serv": 
					data[SIZE-i-1].occupation = Occupation.Protective_serv; break;
				case "Armed-Forces": 
					data[SIZE-i-1].occupation = Occupation.Armed_Forces; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//Relationship
			endIndex = file.indexOf(',', strtIndex);
			temp = file.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "Wife": 
					data[SIZE-i-1].relationship = Relationship.Wife; break;
				case "Own-child": 
					data[SIZE-i-1].relationship = Relationship.Own_child; break;
				case "Husband": 
					data[SIZE-i-1].relationship = Relationship.Husband; break;
				case "Not-in-family": 
					data[SIZE-i-1].relationship = Relationship.Not_in_family; break;
				case "Other-relative": 
					data[SIZE-i-1].relationship = Relationship.Other_relative; break;
				case "Unmarried": 
					data[SIZE-i-1].relationship = Relationship.Unmarried; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//Race
			endIndex = file.indexOf(',', strtIndex);
			temp = file.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "White": 
					data[SIZE-i-1].race = Race.White; break;
				case "Asian-Pac-Islander": 
					data[SIZE-i-1].race = Race.Asian_Pac_Islander; break;
				case "Amer-Indian-Eskimo": 
					data[SIZE-i-1].race = Race.Amer_Indian_Eskimo; break;
				case "Other": 
					data[SIZE-i-1].race = Race.Other; break;
				case "Black": 
					data[SIZE-i-1].race = Race.Black; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//Sex
			endIndex = file.indexOf(',', strtIndex);
			temp = file.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "Male": 
					data[SIZE-i-1].sex = Sex.Male; break;
				case "Female": 
					data[SIZE-i-1].sex = Sex.Female; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//CapitalGain
			endIndex = file.indexOf(',', strtIndex);
			data[SIZE-i-1].capitalGain = Integer.parseInt(file.substring(strtIndex+1, endIndex));
			strtIndex = endIndex + 1;		//Index of space
			
			//CpitalLoss
			endIndex = file.indexOf(',', strtIndex);
			data[SIZE-i-1].capitalLoss = Integer.parseInt(file.substring(strtIndex+1, endIndex));
			strtIndex = endIndex + 1;		//Index of space
			
			//HrsPerWeek
			endIndex = file.indexOf(',', strtIndex);
			data[SIZE-i-1].hoursPerWeek = Integer.parseInt(file.substring(strtIndex+1, endIndex));
			strtIndex = endIndex + 1;		//Index of space
			
			//NativeCountry
			endIndex = file.indexOf(',', strtIndex);
			temp = file.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "United-States": 
					data[SIZE-i-1].nativeCountry = NativeCountry.United_States; break;
				case "Cambodia": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Cambodia; break;
				case "England": 
					data[SIZE-i-1].nativeCountry = NativeCountry.England; break;
				case "Puerto-Rico": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Puerto_Rico; break;
				case "Canada": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Canada; break;
				case "Germany": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Germany; break;
				case "Outlying-US(Guam-USVI-etc)": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Outlying_US_Guam_USVI_etc_; break;
				case "India": 
					data[SIZE-i-1].nativeCountry = NativeCountry.India; break;
				case "Japan": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Japan; break;
				case "Greece": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Greece; break;
				case "South": 
					data[SIZE-i-1].nativeCountry = NativeCountry.South; break;
				case "China": 
					data[SIZE-i-1].nativeCountry = NativeCountry.China; break;
				case "Cuba": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Cuba; break;
				case "Iran": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Iran; break;
				case "Honduras": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Honduras; break;
				case "Philippines": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Philippines; break;
				case "Italy": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Italy; break;
				case "Poland": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Poland; break;
				case "Jamaica": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Jamaica; break;
				case "Vietnam": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Vietnam; break;
				case "Mexico": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Mexico; break;
				case "Portugal": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Portugal; break;
				case "Ireland": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Ireland; break;
				case "France": 
					data[SIZE-i-1].nativeCountry = NativeCountry.France; break;
				case "Dominican-Republic": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Dominican_Republic; break;
				case "Laos": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Laos; break;
				case "Ecuador": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Ecuador; break;
				case "Taiwan": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Taiwan; break;
				case "Haiti": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Haiti; break;
				case "Columbia": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Columbia; break;
				case "Hungary": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Hungary; break;
				case "Guatemala": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Guatemala; break;
				case "Nicaragua": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Nicaragua; break;
				case "Scotland": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Scotland; break;
				case "Thailand": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Thailand; break;
				case "Yugoslavia": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Yugoslavia; break;
				case "El-Salvador": 
					data[SIZE-i-1].nativeCountry = NativeCountry.El_Salvador; break;
				case "Trinadad&Tobago": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Trinadad_Tobago; break;
				case "Peru": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Peru; break;
				case "Hong": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Hong; break;
				case "Holand-Netherlands": 
					data[SIZE-i-1].nativeCountry = NativeCountry.Holand_Netherlands; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//Classification
			endIndex = file.indexOf('\n', strtIndex);
			temp = file.substring(strtIndex+1, endIndex);
			switch(temp) {
				case ">50K": 
					data[SIZE-i-1].classification = Classification.GreaterThan; break;
				case "<=50K": 
					data[SIZE-i-1].classification = Classification.LessThanEqual; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
		}
		
		//System.out.println(data[SIZE-1].marStatus + " " + data[SIZE-1].classification);
		
		for(int j=1; j<=14; j++) {
			if(j == 2 || j == 4 || j == 6 || j == 7 || j == 8 || j == 9 || j == 10 || j == 14)
				continue;
			discretisingContinousValues(j, data);
		}
		
		/*for(int ij=0; ij<100; ij++) {
			System.out.println(data[ij].fnlwgt + " " + data[ij].wClass);	
		}*/
		
		int attr[] = new int[14];
		informationGain(data, 1);
	}
	
}
