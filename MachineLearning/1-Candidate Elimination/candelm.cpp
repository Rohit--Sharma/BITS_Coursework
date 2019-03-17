/* CANDIDATE ELIMINATION ALGORITHM */

#include <iostream>
#include <string>
#include <vector>
#define target(x) x[n_attr-1]
using namespace std;

int n_inst, n_attr;
bool first = true;
vector< vector<string> > generic, specific, input, attribute;

/* function to print a boundary */
inline void print_boundary(vector< vector<string> > boundary)
{
	int i, j;
	for(i = 0; i < boundary.size(); i++)
	{
		cout << "<";
		for(j = 0; j < boundary[i].size(); j++)
		{
			if(j == boundary[i].size() - 1)
				cout << boundary[i][j];
			else
				cout << boundary[i][j] << ",";
		}
		cout << "> ";
	}
	cout << endl;
}

/* function to print all the distinct attributes */
inline void print_distinct_attributes()
{
	int i, j;
	for(i = 0; i < attribute.size(); i++)
	{
		cout << "Attribute " << i+1 << ": ";
		for(j = 0; j < attribute[i].size(); j++)
			cout << attribute[i][j] << " ";
		cout << endl;
	}
}

/* function to print an instance */
inline void print_instance(vector<string> instance)
{
	int i;
	cout << "[ ";
	for(i = 0; i < instance.size(); i++)
		cout << instance[i] << " ";
	cout << "]";
	cout << endl;
}

/* function to check if child is consistent with mother */
inline bool is_consistent(vector<string> child, vector<string> mother)
{
	bool flag = true;
	int i;
	
	for(i = 0; i < mother.size(); i++)
	{
		if(mother[i] == "?" || mother[i] == child[i])
			continue;
		else
		{
			flag = false;
			break;
		}
	}
	
	return flag;
}

/* function to check if a is more general than b */
inline bool is_more_general(vector<string> a, vector<string> b)
{
	int i;
	bool flag = true;
	
	for(i = 0; i < a.size(); i++)
	{
		if((a[i] == "?" && b[i] != "?") || (a[i] == b[i]) || (a[i] != "0" && b[i] == "0"))
			continue;
		else
		{
			flag = false;
			break;
		}
	}
	
	return flag;
}

/* function to fine tune the generic boundary */
inline void fine_tune_specific_boundary()
{
	int i, j, limit = specific.size();
	
	/* remove from specific boundary any hypothesis that is more general than another hypothesis in specific boundary */
	for(i = 0; i < limit; i++)
	{
		for(j = 0; j < limit; j++)
		{
			if(i == j)
				continue;
			
			if(is_more_general(specific[i], specific[j]))
			{
				specific.erase(specific.begin() + i);
				limit--;
				i--;
				break;
			}
		}
	}
}

/* function to fine tune the specific boundary */
inline void fine_tune_generic_boundary()
{
	int i, j, limit = generic.size();
	
	/* remove from generic boundary any hypothesis that is more specific than another hypothesis in generic boundary */
	for(i = 0; i < limit; i++)
	{
		for(j = 0; j < limit; j++)
		{
			if(i == j)
				continue;
			
			if(is_more_general(generic[j], generic[i]))
			{
				generic.erase(generic.begin() + i);
				limit--;
				i--;
				break;
			}
		}
	}
}

/* function to remove hypotheses inconsistent with the instance from a boundary */
inline void remove_inconsistent(vector<string> instance, vector< vector<string> > boundary)
{
	int i = 0;
	
	if(boundary == generic)
	{
		while(i < generic.size())
		{
			if(!is_consistent(instance, generic[i]))
				generic.erase(generic.begin() + i);
			else
				i++;
		}
	}
	
	else
	{
		while(i < specific.size())
		{
			if(!is_consistent(instance, specific[i]))
				specific.erase(specific.begin() + i);
			else
				i++;
		}
	}
}

/* function to remove any hypothesis consistent with a negative training instance from the specific boundary */
inline void remove_consistent_from_specific(vector<string> instance)
{
	int i = 0;
	
	while(i < specific.size())
	{
		if(is_consistent(instance, specific[i]))
			specific.erase(specific.begin() + i);
		else
			i++;
	}	
}

/* function to yield an immediate generalized hypothesis of a hypothesis */
inline vector<string> yield_generalized(vector<string> instance, vector<string> v)
{
	int i;
	bool flag = false;
	vector<string> temp;
	
	for(i = 0; i < v.size(); i++)
	{
		if(instance[i] == v[i])
			temp.push_back(v[i]);
		else
			temp.push_back("?");
	}
	
	return temp;
}

/* function to generalize the specific boundary as a result of a positive training example */
inline void generalize(vector<string> instance)
{
	int i, j, limit = specific.size();
	vector<string> temp, v, w;
	bool flag;
	
	/* for every hypothesis in specific boundary */
	for(i = 0; i < limit; )
	{
		/* if inconsistent with the positive training instance */
		if(!is_consistent(instance, specific[i]))
		{
			/* remove from specific boundary */
			temp = specific[i];
			specific.erase(specific.begin() + i);
			limit--;
			
			/* add to specific boundary all minimal generalizations of temp */
			if(first)
			{
				for(j = 0; j < instance.size()-1; j++)
					w.push_back(instance[j]);
				specific.push_back(w);
				first = false;
			}
			
			else
			{
				v = yield_generalized(instance, temp);
				
				/* add this to specific boundary if some member of generic boundary is more general then the generalized hypothesis */
				flag = false;
				for(j = 0; j < generic.size(); j++)
				{
					if(is_more_general(generic[j], v))
					{
						flag = true;
						break;
					}
				}
				
				if(flag)
					specific.push_back(v);
			}			
			
			temp.clear();
			v.clear();
		}
		
		else
			i++;
	}
}

/* function to specialize the generic boundary as a result of a negative training example */
inline void specialize(vector<string> instance, int index)
{
	int i, j, k, u, limit = generic.size();
	vector<string> temp, modified;
	
	for(i = 0; i < limit; i++)
	{
		temp = generic[i];
		
		/* remove the hypothesis from the generic boundary if it is consistent with the negative training example */
		if(is_consistent(input[index], temp))
		{
			generic.erase(generic.begin() + i);
			limit--;
			i--;
			
			/* add to generic boundary all minimal specializations of hypothesis such that it is inconsistent with negative example */
			for(j = 0; j < temp.size(); j++)
			{
				modified = temp;
				if(temp[j] == "?")
				{
					for(k = 0; k < attribute[j].size(); k++)
					{
						modified[j] = attribute[j][k];
						if(!is_consistent(input[index], modified))
						{
							/* add to generic boundary only if it is more general than some member of specific boundary */
							for(u = 0; u < specific.size(); u++)
							{
								if(is_more_general(modified, specific[u]))
								{
									generic.push_back(modified);
									break;
								}
							}
						}
					}
				}
			}
		}
	}
}

/* function to test the positive and negative training examples */
inline void test(vector<string> instance, int index)
{
	int i, j;
	
	/* positive instance */
	if(target(instance) == "yes")
	{
		remove_inconsistent(instance, generic);
		generalize(instance);
		fine_tune_specific_boundary();
	}
	
	/* negative instance */
	else
	{
		remove_consistent_from_specific(instance);
		specialize(instance, index);
		fine_tune_generic_boundary();
	}
}

int main()
{
	int i, j, k;
	bool found;
	
	/* cout << "Enter the number of instances: "; */
	cin >> n_inst;
	/* cout << "Enter the number of attributes: "; */
	cin >> n_attr;
	
	/* vector declarations */
	string attr_value;
	vector<string> instance;
	
	/* generic boundary initialization */
	for(i = 0; i < n_attr-1; i++)
		instance.push_back("?");
	generic.push_back(instance);
	instance.clear();
	
	cout << "Generic Boundary: ";
	print_boundary(generic);
	
	/* specific boundary initialization */
	for(i = 0; i < n_attr-1; i++)
		instance.push_back("0");
	specific.push_back(instance);
	instance.clear();
	
	cout << "Specific Boundary: ";
	print_boundary(specific);
	
	/* cout << "Enter the instances: "; */
	for(i = 0; i < n_inst; i++)
	{
		for(j = 0; j < n_attr; j++)
		{
			cin >> attr_value;
			instance.push_back(attr_value);
		}
		input.push_back(instance);
		instance.clear();
	}
	
	/* set the size of attribute vector */
	attribute.resize(n_attr-1);
	
	/* check for distinct attributes and store in attribute vector */
	for(j = 0; j < n_attr-1; j++)
	{
		for(i = 0; i < input.size(); i++)
		{
			attr_value = input[i][j];
			
			if(i == 0)
			{
				attribute[j].push_back(attr_value);
				continue;
			}
			
			else
			{
				found = false;
				for(k = 0; k < attribute[j].size(); k++)
				{
					if(attribute[j][k] == attr_value)
					{
						found = true;
						break;
					}
				}
				if(!found)
					attribute[j].push_back(attr_value);
			}
		}
	}
	
	/* print distinct attributes */
	print_distinct_attributes();
	
	/* perform candidate elimination */
	for(i = 0; i < input.size(); i++)
	{
		test(input[i], i);
		cout << "Instance " << i+1 << ": ";
		print_instance(input[i]);
		/*cout << "Specific Boundary: ";
		print_boundary(specific);
		cout << "Generic Boundary: ";
		print_boundary(generic);*/
	}
	
	/* print final specific boundary */
	cout << "Specific Boundary: ";
	print_boundary(specific);
	
	/* print final generic boundary */
	cout << "Generic Boundary: ";
	print_boundary(generic);
	
	return 0;
}

