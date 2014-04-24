using UnityEngine;
using System.Collections;
namespace GameCore
{
	public enum DevelopMode
	{
		DM_Default = -1,
		DM_Develop = 0,
		DM_Release = 1,
		//DM_SandBox,
		//DM_Production
	}
	
	public enum Local
	{
		Local_CN = 2,
		Local_TW = 3,
		Local_KR = 5,
		Local_JP = 6,
		Local_US = 4
	}
	
	public class Config
	{
		private static DevelopMode developMode = DevelopMode.DM_Default;
		public  static int sq;
		public static DevelopMode mCurDevelopMode
		{
			get
			{
				if((int)developMode >= 0 ) return developMode;
				if(PlatformMgr.PlatformHandler.Instance==null)
				{
					return DevelopMode.DM_Release;
				}
				switch(PlatformMgr.PlatformHandler.Instance.GetServerMode())
				{
					case 0: developMode =  DevelopMode.DM_Develop;return  developMode;
					case 1: developMode =  DevelopMode.DM_Release;return  developMode;
					default:return DevelopMode.DM_Release;
				}
			}
			set
			{
				developMode = value;
			}
		}
		public static Local mCurLocal
		{
			get
			{
			    return Local.Local_CN;
				switch(MainMgr.Instance.Region)
				{
					case MBG_REGION.MBG_REGION_CN: return  Local.Local_CN;
					case MBG_REGION.MBG_REGION_TW: return  Local.Local_TW;
					case MBG_REGION.MBG_REGION_JP: return  Local.Local_JP;
					case MBG_REGION.MBG_REGION_US: return  Local.Local_US;
					default :return  Local.Local_CN;
				}
			}
		
		}
		
		
		public static int curDevice
		{
			get
			{
				if(Application.platform == RuntimePlatform.IPhonePlayer)
				{
					return 1;
				}
				else if(Application.platform == RuntimePlatform.Android)
				{
					return 2;
				}
				else 
				{
					return 0;
				}
			}
			
		}
	
		//public static MBG_REGION mRegion;
		public static int ServerID;
		public const int MainVersion = 30;
		public const int ResVersion = 0;
		public const int ServerResVersion = 0;
		public static int currentMainVersion = 0;
		public static int currentResVersion = 0;
		public static int currentServerResVersion=0;
		/*
		public static bool LoadInEditor
		{
			get
			{
				return MainMgr.Instance.LoadInEditor;
			}
		}
		*/
		public static bool LoadInStreaming
		{
			get
			{
			    return false;
				return MainMgr.Instance.LoadInStreamingPath;
			}
		}
		
		public static string affcode = "88888888";
		public static int mBaseHeight = 640;
		public static int mBaseWidth = 960;
		public static int mServerClientTimeOffset = 0;
	    public static bool BaseHeght = true;
		
		public const float mRelativeSizeBaseWidth = 0.00104f;
		public static float BaseWidthRatio = (float)mBaseWidth/Screen.width;
		
		public const float mRelativeSizeBaseHeight = 0.00156f;
		public static float BaseHeightRatio = (float)mBaseHeight/Screen.height;
		

		//public static int mDefaultService = 1;
	}
}
