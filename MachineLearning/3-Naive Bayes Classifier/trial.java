import java.io.*;
import java.util.*;

public class trial
{
	ArrayList<String> files;
	
	public void listFilesForFolder(final File folder) 
	{
		for (final File fileEntry : folder.listFiles()) {
			if (fileEntry.isDirectory()) {
				listFilesForFolder(fileEntry);
			} else {
				//System.out.println(fileEntry.getName());
				files.add(fileEntry.getName().toString());
			}
		}
	}
	/*
	public trial()
	{
		ArrayList<String> arr;
		//arr = getFiles("mini_newsgroups/like");
		System.out.println(numFiles("mini_newsgroups/like"));
	}
	
	public static void main(String srgs[])
	{
		new trial();
	}
	*/
	public ArrayList<String> getFiles(String folderName)
	{
		files = new ArrayList<String>();
		final File folder = new File("./" + folderName);
		listFilesForFolder(folder);
		return files;
	}
	
	public int numFiles(String folderName)
	{
		files = new ArrayList<String>();
		final File folder = new File("./" + folderName);
		listFilesForFolder(folder);
		return files.size();
	}
	
}