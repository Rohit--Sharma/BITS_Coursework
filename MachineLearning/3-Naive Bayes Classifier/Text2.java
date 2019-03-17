import java.util.*;
import java.io.*;

class Text
{
	String classes[] = {"like","dislike"};
	String target;
	String dataset[] = new String[5];
	String test;
	String state[] = {"dislike","like","like","like","dislike"};
	double p[];
	double indivProb[][];
	String like = "",dislike = "",full = "";
	HashMap mapLike,mapDisLike,targetMap;
	int fullFreq;
	double t1,t2;
	
	public Text()
	{
	
		takeTestClassifier();
		trainClassifier();
		testClassifier();
		
		if(t1 > t2)
			System.out.println("Given document will come under: like category");
		
		else
			System.out.println("Given document will come under: dislike category");
	}
	
	public void testClassifier()
	{
		t1 = p[0];
		t2 = p[1];
		//System.out.println(t1 + " "+ t2);
		Iterator it = mapLike.entrySet().iterator();
		while(it.hasNext())
		{
			Map.Entry pairs = (Map.Entry)it.next();
			double d = Double.parseDouble(pairs.getValue().toString());
			//System.out.println(d);
			t1 = t1 * d;
			it.remove();
		}
		
		Iterator it1 = mapDisLike.entrySet().iterator();
		while(it1.hasNext())
		{
			Map.Entry pairs = (Map.Entry)it1.next();
			double d = Double.parseDouble(pairs.getValue().toString());
			//System.out.println(d);
			t2 = t2 * d;
			it1.remove();
		}
		
		System.out.println(t1 + " " + t2);
	}	
	
	public void takeTestClassifier()
	{
		test = readFile("test.txt");
	}
	
	public void trainClassifier() 
	{
		for(int i = 1;i<=5;i++)
		{
			dataset[i-1] = new String();
			dataset[i-1] = readFile("set" + i + ".txt");
		}
		
		// calculating probability of classes
		p = new double[classes.length];
		for(int j = 0;j<classes.length;j++)
		{
			int temp = 0;
			for(int i = 0;i<state.length;i++)
			{
				if(classes[j].equals(state[i]))
					temp++;
			}
			p[j] = temp/(state.length + 0.0);
		}
		
		//distinct for all the classes
		for(int i = 0;i<5;i++)
		{
			if(state[i].equals("like"))
				like += dataset[i] + " ";
			else
				dislike += dataset[i] + " ";
			full += dataset[i] + " ";
		}
		
		// taking all words into arraylist of the target array
		ArrayList<String> arrTarget = new ArrayList<String>();
		arrTarget = makeWordList(test);
		
		ArrayList<String> fullArr = new ArrayList<String>();
		fullArr = makeWordList(full);
		
		fullFreq = getDistinctWordCount(fullArr);
		
		targetMap = new HashMap();
		for(int i = 0;i< getDistinctWordCount(arrTarget);i++)
			targetMap.put(arrTarget.get(i),getFreq(test,arrTarget.get(i)));
	
		mapLike = new HashMap();
		mapDisLike = new HashMap();
		Iterator it = targetMap.entrySet().iterator();
		while(it.hasNext())
		{
			Map.Entry pairs = (Map.Entry)it.next();
			String key = pairs.getKey().toString();
			calculate(mapLike,key,like);
			calculate(mapDisLike,key,dislike);
		    it.remove();
		}
		
		//System.out.println(mapLike);
		//System.out.println(mapDisLike);
	}
	
	public void calculate(HashMap map,String str,String target)
	{
		map.put(str,prob(str,target));
	}
	
	double prob(String str,String target)
	{
		StringTokenizer stk2 = new StringTokenizer(target);
		int n = stk2.countTokens();
		int nc = 0;
		while(stk2.hasMoreTokens())
		{
			if(str.equals(stk2.nextToken()))
				nc++;
		}
		double temp = (nc + 1)/(n + fullFreq + 0.0);
		return temp;
	}
	
	public int getFreq(String str,String s)
	{
		int count = 0;
		StringTokenizer st = new StringTokenizer(str);
		while(st.hasMoreTokens())
		{
			String temp = st.nextToken();
			if(temp.equals(s))
			{
				count++;
			}
		}
		return count;
	}
	
	public ArrayList<String> makeWordList(String str)
	{
		ArrayList<String> listOfWords = new ArrayList<String>();
		StringTokenizer st = new StringTokenizer(str);
		while(st.hasMoreTokens())
		{
			String word = st.nextToken(); 
			if(!listOfWords.contains(word))
				listOfWords.add(word);
		}	
		return listOfWords;
	}

	public int getDistinctWordCount(ArrayList<String> list)
	{
		return list.size();
	}
	
	String readFile(String file)
	{
		BufferedReader reader = null;
		try
		{
			reader = new BufferedReader( new FileReader (file));
		}
		catch(Exception e){}
		String line = null;
		StringBuilder  stringBuilder = new StringBuilder();
		try
		{
			while((line = reader.readLine()) != null)
			{
				stringBuilder.append(line);
			}
		}
		catch(Exception e){}
		return stringBuilder.toString();
	}
	
	
	public static void main(String args[])
	{
		new Text();
	}
}