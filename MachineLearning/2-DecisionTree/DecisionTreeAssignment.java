package DecisionTree;

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
	GreaterThan(1),
	LessThanEqual(0);
		
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

class DecisionTreeAssignment
{
	public static int SIZE = 0;	// = 32561;
	
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
		/*if(p1 == 0) {
			return -p2 * Math.log(p2) / Math.log(2);
		} else if(p2 == 0) {
			return -p1 * Math.log(p1) / Math.log(2);
		}*/
		if(p1 == 0 || p2 == 0) {
			return 0;
		}
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
				break;
			}
			case 3: {					//fnlwgt
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
				break;
			} 
			case 5: {					//Education-num
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
				break;
			} 
			case 11: {				//capital-gain
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
				break;
			} 
			case 12: {				//capital-loss
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
				break;
			} 
			case 13: {				//Hoursperweek
				int mean = 0;
				for(int i=0; i<SIZE; i++) {
					mean += data[i].hoursPerWeek;
				}
				mean /= SIZE;
				//System.out.println("Mean= "+ mean);
				for(int i=0; i<SIZE; i++) {
					if(data[i].hoursPerWeek <= mean)
						data[i].hoursPerWeek = 0;		//LOW
					else
						data[i].hoursPerWeek = 1;		//High
				}
				break;
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
		//System.out.println("Ent: " + ent);
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
							if(p1 == 0 || p2 == 0) {
								continue;
							}
							else if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				/*System.out.println("1: ");
				for(int i=0; i<2; i++)
					for(int j=0; j<3; j++)
						System.out.println("ij: " + i + " " + j + ": " + arr[i][j] + " ");*/
				break;
			} 
			case 2: {					//Workclass
				
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
							if(p1 == 0 || p2 == 0) {
								continue;
							}
							else 
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
					//System.out.println("	nValues: " + arr[i][0] + ", nGreater: " + arr[i][1] + ", nLess: " + arr[i][2]);
				}
				/*System.out.println("2: ");
				for(int i=0; i<Workclass.nValues; i++) {
					for(int j=0; j<3; j++)
						System.out.print(arr[i][j] + " ");
					System.out.println();
				}*/
				break;
				
			} 
			case 3: {					//fnlwgt
				int arr[][] = new int[2][3];
				for (int i=0; i<sample.length; i++) {
					  try {
						arr[sample[i].fnlwgt][0]++;
						if(sample[i].classification == Classification.GreaterThan)
							arr[sample[i].fnlwgt][1]++;
						else
							arr[sample[i].fnlwgt][2]++;
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
							
							if(p1 == 0 || p2 == 0) {
								continue;
							}
							else 
							//System.out.println("p1: " + p1 + " ,p2: " + p2);
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				/*System.out.println("3: ");
				for(int i=0; i<2; i++)
					for(int j=0; j<3; j++)
						System.out.println("ij: " + i + " " + j + ": " + arr[i][j] + " ");*/
				break;
			} 
			case 4: {					//Education
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
							if(p1 == 0 || p2 == 0) {
								continue;
							}
							else 
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				/*System.out.println("4: ");
				for(int i=0; i<Education.nValues; i++) {
					for(int j=0; j<3; j++)
						System.out.print(arr[i][j] + " ");
					System.out.println();
				}*/
				break;
			} 
			case 5: {					//Education-num
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
							if(p1 == 0 || p2 == 0) {
								continue;
							}
							else 
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				/*System.out.println("5: ");
				for(int i=0; i<2; i++)
					for(int j=0; j<3; j++)
						System.out.println("ij: " + i + " " + j + ": " + arr[i][j] + " ");*/
				break;
			} 
			case 6: {					//Marital status
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
							if(p1 == 0 || p2 == 0) {
								continue;
							}
							else 
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				/*System.out.println("6: ");
				for(int i=0; i<MaritalStatus.nValues; i++) {
					for(int j=0; j<3; j++)
						System.out.print(arr[i][j] + " ");
					System.out.println();
				}*/
				break;
			} 
			case 7: {					//Occupation
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
							if(p1 == 0 || p2 == 0) {
								continue;
							}
							else 
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				/*System.out.println("7: ");
				for(int i=0; i<Occupation.nValues; i++) {
					for(int j=0; j<3; j++)
						System.out.print(arr[i][j] + " ");
					System.out.println();
				}*/
				break;
			} 
			case 8: {					//Relationship
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
							if(p1 == 0 || p2 == 0) {
								continue;
							}
							else 
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				/*System.out.println("8: ");
				for(int i=0; i<Relationship.nValues; i++) {
					for(int j=0; j<3; j++)
						System.out.print(arr[i][j] + " ");
					System.out.println();
				}*/
				break;
			} 
			case 9: {					//Race
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
							if(p1 == 0 || p2 == 0) {
								continue;
							}
							else 
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				/*System.out.println("9: ");
				for(int i=0; i<Race.nValues; i++) {
					for(int j=0; j<3; j++)
						System.out.print(arr[i][j] + " ");
					System.out.println();
				}*/
				break;
			} 
			case 10: {				//Sex
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
							if(p1 == 0 || p2 == 0) {
								continue;
							}
							else 
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				/*System.out.println("10: ");
				for(int i=0; i<Sex.nValues; i++) {
					for(int j=0; j<3; j++)
						System.out.print(arr[i][j] + " ");
					System.out.println();
				}*/
				break;
			} 
			case 11: {				//capital-gain
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
							if(p1 == 0 || p2 == 0) {
								continue;
							}
							else 
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				/*System.out.println("11: ");
				for(int i=0; i<2; i++)
					for(int j=0; j<3; j++)
						System.out.println("ij: " + i + " " + j + ": " + arr[i][j] + " ");*/
				break;
			} 
			case 12: {				//capital-loss
				/*int arr[][] = new int[2][3];
				for (int i=0; i<sample.length; i++) {
					  try {
						arr[sample[i].capitalLoss][0]++;
						if(sample[i].classification == Classification.GreaterThan)
							arr[sample[i].capitalLoss][1]++;
						else
							arr[sample[i].capitalLoss][2]++;
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
				System.out.println("12: ");
				for(int i=0; i<2; i++)
					for(int j=0; j<3; j++)
						System.out.println("ij: " + i + " " + j + ": " + arr[i][j] + " ");
				break;*/
				int arr[][] = new int[2][3];
				for (int i=0; i<sample.length; i++) {
					  try {
						arr[sample[i].capitalLoss][0]++;
						if(sample[i].classification == Classification.GreaterThan)
							arr[sample[i].capitalLoss][1]++;
						else
							arr[sample[i].capitalLoss][2]++;
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
							// System.out.println(p1 + " " + p2);
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				// System.out.println("12: ");
				for(int i=0; i<2; i++)
					for(int j=0; j<3; j++)
						// System.out.println("ij: " + i + " " + j + ": " + arr[i][j] + " ");
				break;
			} 
			case 13: {				//Hoursperweek
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
				/*System.out.println("13: ");
				for(int i=0; i<2; i++)
					for(int j=0; j<3; j++)
						System.out.println("ij: " + i + " " + j + ": " + arr[i][j] + " ");*/
				break;
			} 
			case 14: {				//Country
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
							if(p1 == 0 || p2 == 0) {
								continue;
							}
							else 
							if(p1 > 0 && p2 > 0)
								weightedEntropyOfValues -= (double)arr[i][0] / sample.length * 
									(-p1 * Math.log(p1) / Math.log(2) - p2 * Math.log(p2) / Math.log(2));
						} catch(Exception e) {
							e.printStackTrace();
						}
					}
				}
				/*System.out.println("14: ");
				for(int i=0; i<NativeCountry.nValues; i++) {
					for(int j=0; j<3; j++)
						System.out.print(arr[i][j] + " ");
					System.out.println();
				}*/
				break;
			}
		}
		//System.out.println("Entropy[" + attr + "]: " + ent + " " + weightedEntropyOfValues);
		return ent + weightedEntropyOfValues;
	}
	
	private static int decisionAttribute(Attribute []node, int []attributes) {
		double max = -1;
		int maxIdx = -1;
		for(int i=0; i<14; i++) {
			//System.out.println("i: " + i + "Information Gain in decAttr: " + informationGain(node, i+1));
			if(attributes[i] != -1 && max < informationGain(node, i+1)) {
				max = informationGain(node, i+1);
				maxIdx = i+1;
				//System.out.println("i: " + i + ", max: " + max);
			}
		}
		//System.out.println("    Info gain: " + max + ", maxIdx: " + maxIdx);
		return maxIdx;
	}
	
	public static Tree<Integer> buildDecisionTree(Attribute []node, int []attributes)
	{
		//System.out.println("12:::::: " + informationGain(node, 12));
		
		
		//System.out.print("Attributes: ");
		for(int ijk = 0; ijk < 14; ijk++) {
			//System.out.print(attributes[ijk] + " ");
		}
		//System.out.println();
		
		Tree<Integer> root = new Tree<Integer>(-1);
		
		int nPos = 0;							// nPos = number of positive examples
		for (Attribute ex : node) {
			if(ex.classification == Classification.GreaterThan)
				nPos++;							
		}
		
		//System.out.println("No.... of positive examples="+nPos);
		int attLen = 0;
		for(int i=0; i<attributes.length; i++) {
			if(attributes[i] != -1)
				attLen++;
		}
		
		if(nPos == node.length) {				// If all examples are positive
			root.clf = true;					//		return single node tree, 'root' with clf = +
		} else if(nPos == 0) {					// If all examples are negative
			root.clf = false;					//		return single node tree, 'root' with clf = -
		} else if(attLen == 0) {				// If attributes is empty
			if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
				root.clf = true;
			else
				root.clf = false;
		} else {
			
			int bestAttribute = decisionAttribute(node, attributes);	
			 //System.out.println("bestAttribute: " + bestAttribute);
			if(bestAttribute != -1) {
				attributes[bestAttribute - 1] = -1;	// Report this attribute as being used up.
				root.data = bestAttribute;

				Tree<Integer> child;
				switch(bestAttribute) {
					case 1: {						// age
						for (int i=0; i<2; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);		// -3 : leaf
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].age == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) {
								if(node[j].age == i)
									subsetExamplesVi[k++] = node[j];
							}

							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
						}
						break;
					}
					case 2: {						// wclass
						for (int i=0; i<Workclass.nValues; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);
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
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
						}
						break;
					}
					case 3: {						// fnlwgt
						for (int i=0; i<2; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].fnlwgt == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) 
								if(node[j].fnlwgt == i)
									subsetExamplesVi[k++] = node[j];

							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
						}
						break;
					}
					case 4: {						// education
						for (int i=0; i<Education.nValues; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].education != null && node[j].education.getValue() == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) 
								if(node[j].education != null && node[j].education.getValue() == i)
									subsetExamplesVi[k++] = node[j];

							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
						}
						break;
					}
					case 5: {						// eduNum
						for (int i=0; i<2; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].educationNum == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) 
								if(node[j].educationNum == i)
									subsetExamplesVi[k++] = node[j];

							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
						}
						break;
					}
					case 6: {						// maritalStat
						for (int i=0; i<MaritalStatus.nValues; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].marStatus != null && node[j].marStatus.getValue() == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) 
								if(node[j].marStatus != null && node[j].marStatus.getValue() == i)
									subsetExamplesVi[k++] = node[j];

							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
						}
						break;
					}
					case 7: {						// Occp
						//System.out.println("ocpVal: " + Occupation.nValues);
						for (int i=0; i<Occupation.nValues; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].occupation != null && node[j].occupation.getValue() == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) 
								if(node[j].occupation != null && node[j].occupation.getValue() == i)
									subsetExamplesVi[k++] = node[j];

							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
							/*if(child.parent != null)
								System.out.println("child7 ::: " + child.parent.data);
							else
								System.out.println("Hello701");*/
							
						}
						break;
						
						
					}
					case 8: {						// Rela
						for (int i=0; i<Relationship.nValues; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].relationship != null && node[j].relationship.getValue() == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) 
								if(node[j].relationship != null && node[j].relationship.getValue() == i)
									subsetExamplesVi[k++] = node[j];

							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
						}
						break;
					}
					case 9: {						// Race
						for (int i=0; i<Race.nValues; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].race != null && node[j].race.getValue() == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) 
								if(node[j].race != null && node[j].race.getValue() == i)
									subsetExamplesVi[k++] = node[j];

							//for (int j=0; j<node.length; j++) 
							//	System.out.println("Race: " + node[j].race);

							// System.out.println("No. of ex= "+subsetExamplesVi.length);
							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
						}
						break;
					}
					case 10: {						// Sex
						for (int i=0; i<Sex.nValues; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].sex != null && node[j].sex.getValue() == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) 
								if(node[j].sex != null && node[j].sex.getValue() == i)
									subsetExamplesVi[k++] = node[j];

							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
						}
						break;
					}
					case 11: {						// CapGain
						for (int i=0; i<2; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].capitalGain == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) 
								if(node[j].capitalGain == i)
									subsetExamplesVi[k++] = node[j];

							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
						}
						break;
					}
					case 12: {						// CapLoss
						for (int i=0; i<2; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].capitalLoss == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) 
								if(node[j].capitalLoss == i)
									subsetExamplesVi[k++] = node[j];

							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
							} else {
								// System.out.println("bestAttribute: " + bestAttribute);
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
							for(int kl = 0; kl < 14; kl++) {
								// System.out.println("Information gain: " + informationGain(subsetExamplesVi, kl+1));
							}
							// System.out.println("12**");
						}
						break;
					}
					case 13: {						// HrsPerWeek
						for (int i=0; i<2; i++) {
							child = new Tree<Integer>(-3);	// child for ith attribute
							//child = root.addChild(i);
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].hoursPerWeek == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) 
								if(node[j].hoursPerWeek == i)
									subsetExamplesVi[k++] = node[j];


							//System.out.println("HoursPerWek "+subsetExamplesVi[i].hoursPerWeek);

							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2) {			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
									child.data = 0;
								}	
								else {
									child.clf = false;
									child.data=0;
								}
								//System.out.println(child.clf);

							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
							for(int kl = 0; kl < 14; kl++) {
								// System.out.println("Information gain: " + informationGain(subsetExamplesVi, kl+1));
							}
							// System.out.println("*");
							/*if(child.parent != null)
								System.out.println("child13 ::: " + child.parent.data);
							else
								System.out.println("Hello7");*/
						}
						break;
					}
					case 14: {						// natCntry
						for (int i=0; i<NativeCountry.nValues; i++) {
							//child = new Tree<Integer>(i);	// child for ith attribute
							child = root.addChild(-3);
							int count = 0, k=0;
							for (int j=0; j<node.length; j++) 
								if(node[j].nativeCountry != null && node[j].nativeCountry.getValue() == i)
									count++;
							Attribute []subsetExamplesVi = new Attribute[count];
							// initialise subsetExamplesVi
							for (int j=0; j<node.length; j++) 
								if(node[j].nativeCountry != null && node[j].nativeCountry.getValue() == i)
									subsetExamplesVi[k++] = node[j];

							if(subsetExamplesVi.length == 0) {	// This branch is leaf branch and clf = most common value
								if(nPos > node.length/2)			//		return single node tree, 'root' with clf = most common value
									child.clf = true;
								else
									child.clf = false;
								//System.out.println(child.clf);
							} else {
								child = buildDecisionTree(subsetExamplesVi, attributes); // replace attributes with attributes - bestAttribute
							}
							root.children.add(child);
						}
						break;
					}
				}
			}
		}
		return root;
	}
	
	public static boolean classify(Tree<Integer> root, Attribute att)
	{
		if(root.isLeaf()) {
			return root.clf;
		} else {
			switch(root.data) {
				case 1: {
					return classify(root.children.get(att.age), att);			// recursively go to the correct child depending on the 
					//break;										// value of the age. "E get(int index)" func of ll is used to get index'th child
				}
				case 2: {
					return classify(root.children.get(att.wClass.getValue()), att);
					// break;
				}
				case 3: {
					return classify(root.children.get(att.fnlwgt), att);
					// break;
				}
				case 4: {
					return classify(root.children.get(att.education.getValue()), att);
					// break;
				}
				case 5: {
					return classify(root.children.get(att.educationNum), att);
					// break;
				}
				case 6: {
					return classify(root.children.get(att.marStatus.getValue()), att);
					// break;
				}
				case 7: {
					//System.out.println("Exc: " + att.occupation);
					return classify(root.children.get(att.occupation.getValue()), att);
					// break;
				}
				case 8: {
					//System.out.println("Exc: " + att.relationship.getValue());
					return classify(root.children.get(att.relationship.getValue()), att);
					// break;
				}
				case 9: {
					return classify(root.children.get(att.race.getValue()), att);
					// break;
				}
				case 10: {
					return classify(root.children.get(att.sex.getValue()), att);
					// break;
				}
				case 11: {
					return classify(root.children.get(att.capitalGain), att);
					// break;
				}
				case 12: {
					return classify(root.children.get(att.capitalLoss), att);
					// break;
				}
				case 13: {
					return classify(root.children.get(att.hoursPerWeek), att);
					// break;
				}
				case 14: {
					return classify(root.children.get(att.nativeCountry.getValue()), att);
					// break;
				}
				default: {
					// System.out.println("Classify error");
					return false;
				}
			}
		}
	}
	
	public static void testTree(Tree<Integer> root, Attribute[] testData)		//Actually test data must be attribute array filled from another file
	{
		int count = 0;
		for(Attribute current : testData) {
			int val;
			if(classify(root, current))
				val = 1;
			else val = 0;
			if(current.classification.getValue() == val)
				count++;	
		}
		
		System.out.println("Number of examples correctly classified: " + count);
		
		System.out.println("\nAccuracy of the testing: ((" + count  + "/" +  testData.length + ") * 100) = " + count * 100.0 / testData.length + "\n");
	}
	
	public static void main(String ...args) throws IOException
	{
		FileReader in = null;
		
		int testSize = 0;
		
		//Read the entire file into a String
		
		if(args.length < 2) {
			System.out.println("Usage: \n\tCompile: javac -d . *.java \n\tRun: java DecisionTree.DecisionTreeAssignment [Training data] [Testing data]");
			System.out.println("Program ends.");
			return;
		}
		
		String file = new Scanner(new File(args[0])).useDelimiter("\\Z").next(), temp;
		String filet = new Scanner(new File(args[1])).useDelimiter("\\Z").next();
		
		// Initialising the size of the file
		for(int p = 0; p < file.length(); p++) {
			if(file.charAt(p) == '\n')
				SIZE++;
		}
		
		for(int p = 0; p < filet.length(); p++) {
			if(filet.charAt(p) == '\n')
				testSize++;
		}
		
		System.out.println("\nSize of training data: "+SIZE + "\nSize of testing data: " + testSize + "\n");
		
		Attribute data[] = new Attribute[SIZE];
		Attribute[] testData = new Attribute[testSize];
		
		int strtIndex = 0, endIndex, i = SIZE;
		//ReadInput into arrays
		while(i-- != 0) {	
			
			//System.out.println(SIZE-i-1);
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
		
		strtIndex = 0; i = testSize;
		//ReadInput into arrays
		while(i-- != 0) {	
			
			//System.out.println(testSize-i-1);
			testData[testSize-i-1] = new Attribute();
			
			//Age
			endIndex = filet.indexOf(',', strtIndex);
			testData[testSize-i-1].age = Integer.parseInt(filet.substring(strtIndex, endIndex));
			strtIndex = endIndex + 1;		//Index of space
			
			//Workclass
			endIndex = filet.indexOf(',', strtIndex);
			temp = filet.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "Private": 
					testData[testSize-i-1].wClass = Workclass.Private; break;
				case "Self-emp-not-inc": 
					testData[testSize-i-1].wClass = Workclass.Self_emp_not_inc; break;
				case "Self-emp-inc": 
					testData[testSize-i-1].wClass = Workclass.Self_emp_inc; break;
				case "Federal-gov": 
					testData[testSize-i-1].wClass = Workclass.Federal_gov; break;
				case "Local-gov": 
					testData[testSize-i-1].wClass = Workclass.Local_gov; break;
				case "State-gov": 
					testData[testSize-i-1].wClass = Workclass.State_gov; break;
				case "Without-pay": 
					testData[testSize-i-1].wClass = Workclass.Without_pay; break;
				case "Never-worked": 
					testData[testSize-i-1].wClass = Workclass.Never_worked; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//FNLWGT
			endIndex = filet.indexOf(',', strtIndex);
			testData[testSize-i-1].fnlwgt = Integer.parseInt(filet.substring(strtIndex+1, endIndex));
			strtIndex = endIndex + 1;		//Index of space
			
			//Education
			endIndex = filet.indexOf(',', strtIndex);
			temp = filet.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "Bachelors": 
					testData[testSize-i-1].education = Education.Bachelors; break;
				case "Some-college": 
					testData[testSize-i-1].education = Education.Some_college; break;
				case "11th": 
					testData[testSize-i-1].education = Education.n11th; break;
				case "HS-grad": 
					testData[testSize-i-1].education = Education.HS_grad; break;
				case "Prof-school": 
					testData[testSize-i-1].education = Education.Prof_school; break;
				case "Assoc-acdm": 
					testData[testSize-i-1].education = Education.Assoc_acdm; break;
				case "Assoc-voc": 
					testData[testSize-i-1].education = Education.Assoc_voc; break;
				case "9th": 
					testData[testSize-i-1].education = Education.n9th; break;
				case "7th-8th": 
					testData[testSize-i-1].education = Education.n7th_8th; break;
				case "12th": 
					testData[testSize-i-1].education = Education.n12th; break;
				case "Masters": 
					testData[testSize-i-1].education = Education.Masters; break;
				case "1st-4th": 
					testData[testSize-i-1].education = Education.n1st_4th; break;
				case "10th": 
					testData[testSize-i-1].education = Education.n10th; break;
				case "Doctorate": 
					testData[testSize-i-1].education = Education.Doctorate; break;
				case "5th-6th": 
					testData[testSize-i-1].education = Education.n5th_6th; break;
				case "Preschool": 
					testData[testSize-i-1].education = Education.Preschool; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//eduNum
			endIndex = filet.indexOf(',', strtIndex);
			testData[testSize-i-1].educationNum = Integer.parseInt(filet.substring(strtIndex+1, endIndex));
			strtIndex = endIndex + 1;		//Index of space
			
			//Marital Status
			endIndex = filet.indexOf(',', strtIndex);
			temp = filet.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "Married-civ-spouse": 
					testData[testSize-i-1].marStatus = MaritalStatus.Married_civ_spouse; break;
				case "Divorced": 
					testData[testSize-i-1].marStatus = MaritalStatus.Divorced; break;
				case "Never-married": 
					testData[testSize-i-1].marStatus = MaritalStatus.Never_married; break;
				case "Separated": 
					testData[testSize-i-1].marStatus = MaritalStatus.Separated; break;
				case "Widowed": 
					testData[testSize-i-1].marStatus = MaritalStatus.Widowed; break;
				case "Married-spouse-absent": 
					testData[testSize-i-1].marStatus = MaritalStatus.Married_spouse_absent; break;
				case "Married-AF-spouse": 
					testData[testSize-i-1].marStatus = MaritalStatus.Married_AF_spouse; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//Occupation
			endIndex = filet.indexOf(',', strtIndex);
			temp = filet.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "Tech-support": 
					testData[testSize-i-1].occupation = Occupation.Tech_support; break;
				case "Craft-repair": 
					testData[testSize-i-1].occupation = Occupation.Craft_repair; break;
				case "Other-service": 
					testData[testSize-i-1].occupation = Occupation.Other_service; break;
				case "Sales": 
					testData[testSize-i-1].occupation = Occupation.Sales; break;
				case "Exec-managerial": 
					testData[testSize-i-1].occupation = Occupation.Exec_managerial; break;
				case "Prof-specialty": 
					testData[testSize-i-1].occupation = Occupation.Prof_specialty; break;
				case "Handlers-cleaners": 
					testData[testSize-i-1].occupation = Occupation.Handlers_cleaners; break;
				case "Machine-op-inspct": 
					testData[testSize-i-1].occupation = Occupation.Machine_op_inspct; break;
				case "Adm-clerical": 
					testData[testSize-i-1].occupation = Occupation.Adm_clerical; break;
				case "Farming-fishing": 
					testData[testSize-i-1].occupation = Occupation.Farming_fishing; break;
				case "Transport-moving": 
					testData[testSize-i-1].occupation = Occupation.Transport_moving; break;
				case "Priv-house-serv": 
					testData[testSize-i-1].occupation = Occupation.Priv_house_serv; break;
				case "Protective-serv": 
					testData[testSize-i-1].occupation = Occupation.Protective_serv; break;
				case "Armed-Forces": 
					testData[testSize-i-1].occupation = Occupation.Armed_Forces; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//Relationship
			endIndex = filet.indexOf(',', strtIndex);
			temp = filet.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "Wife": 
					testData[testSize-i-1].relationship = Relationship.Wife; break;
				case "Own-child": 
					testData[testSize-i-1].relationship = Relationship.Own_child; break;
				case "Husband": 
					testData[testSize-i-1].relationship = Relationship.Husband; break;
				case "Not-in-family": 
					testData[testSize-i-1].relationship = Relationship.Not_in_family; break;
				case "Other-relative": 
					testData[testSize-i-1].relationship = Relationship.Other_relative; break;
				case "Unmarried": 
					testData[testSize-i-1].relationship = Relationship.Unmarried; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//Race
			endIndex = filet.indexOf(',', strtIndex);
			temp = filet.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "White": 
					testData[testSize-i-1].race = Race.White; break;
				case "Asian-Pac-Islander": 
					testData[testSize-i-1].race = Race.Asian_Pac_Islander; break;
				case "Amer-Indian-Eskimo": 
					testData[testSize-i-1].race = Race.Amer_Indian_Eskimo; break;
				case "Other": 
					testData[testSize-i-1].race = Race.Other; break;
				case "Black": 
					testData[testSize-i-1].race = Race.Black; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//Sex
			endIndex = filet.indexOf(',', strtIndex);
			temp = filet.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "Male": 
					testData[testSize-i-1].sex = Sex.Male; break;
				case "Female": 
					testData[testSize-i-1].sex = Sex.Female; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//CapitalGain
			endIndex = filet.indexOf(',', strtIndex);
			testData[testSize-i-1].capitalGain = Integer.parseInt(filet.substring(strtIndex+1, endIndex));
			strtIndex = endIndex + 1;		//Index of space
			
			//CpitalLoss
			endIndex = filet.indexOf(',', strtIndex);
			testData[testSize-i-1].capitalLoss = Integer.parseInt(filet.substring(strtIndex+1, endIndex));
			strtIndex = endIndex + 1;		//Index of space
			
			//HrsPerWeek
			endIndex = filet.indexOf(',', strtIndex);
			testData[testSize-i-1].hoursPerWeek = Integer.parseInt(filet.substring(strtIndex+1, endIndex));
			strtIndex = endIndex + 1;		//Index of space
			
			//NativeCountry
			endIndex = filet.indexOf(',', strtIndex);
			temp = filet.substring(strtIndex+1, endIndex);
			switch(temp) {
				case "United-States": 
					testData[testSize-i-1].nativeCountry = NativeCountry.United_States; break;
				case "Cambodia": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Cambodia; break;
				case "England": 
					testData[testSize-i-1].nativeCountry = NativeCountry.England; break;
				case "Puerto-Rico": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Puerto_Rico; break;
				case "Canada": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Canada; break;
				case "Germany": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Germany; break;
				case "Outlying-US(Guam-USVI-etc)": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Outlying_US_Guam_USVI_etc_; break;
				case "India": 
					testData[testSize-i-1].nativeCountry = NativeCountry.India; break;
				case "Japan": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Japan; break;
				case "Greece": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Greece; break;
				case "South": 
					testData[testSize-i-1].nativeCountry = NativeCountry.South; break;
				case "China": 
					testData[testSize-i-1].nativeCountry = NativeCountry.China; break;
				case "Cuba": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Cuba; break;
				case "Iran": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Iran; break;
				case "Honduras": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Honduras; break;
				case "Philippines": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Philippines; break;
				case "Italy": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Italy; break;
				case "Poland": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Poland; break;
				case "Jamaica": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Jamaica; break;
				case "Vietnam": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Vietnam; break;
				case "Mexico": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Mexico; break;
				case "Portugal": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Portugal; break;
				case "Ireland": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Ireland; break;
				case "France": 
					testData[testSize-i-1].nativeCountry = NativeCountry.France; break;
				case "Dominican-Republic": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Dominican_Republic; break;
				case "Laos": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Laos; break;
				case "Ecuador": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Ecuador; break;
				case "Taiwan": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Taiwan; break;
				case "Haiti": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Haiti; break;
				case "Columbia": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Columbia; break;
				case "Hungary": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Hungary; break;
				case "Guatemala": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Guatemala; break;
				case "Nicaragua": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Nicaragua; break;
				case "Scotland": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Scotland; break;
				case "Thailand": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Thailand; break;
				case "Yugoslavia": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Yugoslavia; break;
				case "El-Salvador": 
					testData[testSize-i-1].nativeCountry = NativeCountry.El_Salvador; break;
				case "Trinadad&Tobago": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Trinadad_Tobago; break;
				case "Peru": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Peru; break;
				case "Hong": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Hong; break;
				case "Holand-Netherlands": 
					testData[testSize-i-1].nativeCountry = NativeCountry.Holand_Netherlands; break;
			}
			strtIndex = endIndex + 1;		//Index of space
			
			//Classification
			endIndex = filet.indexOf('.', strtIndex);
			temp = filet.substring(strtIndex+1, endIndex);
			//System.out.println(temp);
			switch(temp) {
				case ">50K": 
					testData[testSize-i-1].classification = Classification.GreaterThan; break;
				case "<=50K": 
					testData[testSize-i-1].classification = Classification.LessThanEqual; break;
			}
			strtIndex = endIndex + 2;		//Index of space
			
		}
		
		//System.out.println(data[SIZE-1].marStatus + " " + data[SIZE-1].classification);
		
		//Discretising attributes
		for(int j=1; j<=14; j++) {
			if(j == 2 || j == 4 || j == 6 || j == 7 || j == 8 || j == 9 || j == 10 || j == 14)
				continue;
			discretisingContinousValues(j, data);
			
		}
		
		PrintWriter dataCopy= new PrintWriter("discretized.txt");
	
		// Printing data
		for(int ij=0; ij<SIZE; ij++) {
			
			dataCopy.print(data[ij].age+ " ") ;
			dataCopy.print(data[ij].wClass+ " ");
			dataCopy.print(data[ij].fnlwgt+ " ");	
			dataCopy.print(data[ij].education+ " ");	
			dataCopy.print(data[ij].educationNum+ " ");
			dataCopy.print(data[ij].marStatus+ " ");	
			dataCopy.print(data[ij].occupation+ " ");
			dataCopy.print(data[ij].relationship+ " ");
			dataCopy.print(data[ij].race+ " ");	
			dataCopy.print(data[ij].sex+ " ");
			dataCopy.print(data[ij].capitalGain+ " ");
			dataCopy.print(data[ij].capitalLoss+ " ");	
			dataCopy.print(data[ij].hoursPerWeek+ " ");
			dataCopy.println(data[ij].nativeCountry);
		
		}
		if(dataCopy != null)
		   dataCopy.close();
		
		int attr[] = new int[14];
		for(int j=0; j<14; j++)
			attr[j] = j + 1;			// attributes are 1 indexed
		
		
						/*for(int kl = 0; kl < 14; kl++) {
							System.out.println("Information gain: " + informationGain(data, kl+1));
						}
						System.out.println("*");*/
		
		Tree<Integer> root = buildDecisionTree(data, attr);
		
		System.out.println("\nDecision Tree created and also written to the file \"decisionTree.txt\" in the form of pre-order traversal.\n");
		
		TreeTestDrive.drawTree();
		
		TreeTestDrive.preOrderTraversal(root);
		
		testTree(root, testData);
		
		TreeTestDrive.closeTree();
		
		System.out.println("Program ends.");
	}
	
	
}
