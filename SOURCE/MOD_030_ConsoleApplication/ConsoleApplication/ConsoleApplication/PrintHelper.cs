﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Text;
using System.Windows.Forms;

namespace ConsoleApplication
{
    public static class PrintHelper
    {

        public static void welcome()
        {
            // print welcome,license .... Doc , explanat

            Console.WriteLine("welcome, doc, explant");
        }

        public static void exit()
        {
            // print welcome,license .... Doc , explanat

            Console.WriteLine("thanks for working with us, please donate under ...");
        }

        public static void loopExplanation()
        {
            // entscheide
            try
            {
                Console.Clear();
            }
            catch (Exception)
            {
                // Wenn nicht dann halt nicht
            }
            Console.WriteLine("What do you want to do?");
            Console.WriteLine("Type \"Validate\" to Validate an AML-File");
            Console.WriteLine("Type \"Compress\" or \"Decompress\" to Compress or Decompress an existing AMLX-File");
            Console.WriteLine("Type \"Quit\" or \"Exit\" to exit the Program");
        }

        public static void DeCompressor_Choosage(bool Compress = true)
        {
            Console.Clear();
            if (Compress)
                Console.WriteLine("Compress a Folder to an AMLX-File\n");
            else
                Console.WriteLine("De-Compress an AMLX-File to a Folder\n");
        }

        public static void PrepareConsoleForNewInput()
        {
            Console.SetCursorPosition(0, Console.CursorTop - 1);
            Console.WriteLine("                                                                                                                                                        ");
            Console.SetCursorPosition(0, Console.CursorTop - 2);
        }

        public static string GetFile(string Filename, string FileExtensions)
        {
            OpenFileDialog dialog = new OpenFileDialog
            {
                Multiselect = false,
                Title = "Open "+Filename,
                Filter = Filename+"|"+FileExtensions
            };
            if (dialog.ShowDialog() == DialogResult.OK && File.Exists(@dialog.FileName))
                return @dialog.FileName;
            else
                return null;
        }

        public static string GetDirectory()
        {
            FolderBrowserDialog dialog = new FolderBrowserDialog();
            if (dialog.ShowDialog() == DialogResult.OK && Directory.Exists(@dialog.SelectedPath) && File.GetAttributes(@dialog.SelectedPath).HasFlag(FileAttributes.Directory))
                return @dialog.SelectedPath;
            else
                return null;
        }
    }
}
