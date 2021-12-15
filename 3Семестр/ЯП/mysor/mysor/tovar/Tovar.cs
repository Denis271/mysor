using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;
using System.Xml;

namespace mysor
{

	public class TovarDataArray
	{

		[XmlArray("tovars")]
		[XmlArrayItem("tovar")]
		public List<TovarData> data = new List<TovarData>();
	}
	[Serializable]
	[XmlRoot("dataTovar")]
	public class TovarData
	{
		[XmlAttribute("name")]
		public string name;
		[XmlAttribute("price")]
		public string price;
	}

	class Tovar
	{
		string nameFile = "tovar.txt";
		XmlSerializer serializer = new XmlSerializer(typeof(TovarDataArray));
		public void setTovar(TovarData dataArray)
		{
			TovarDataArray allData = getTovar();
			allData.data.Add(dataArray);
			using (var fs = new FileStream(nameFile, FileMode.Create))
			{
				serializer.Serialize(fs, allData);
			}
		}
		public TovarData tovarIndex(int index)
        {
			TovarDataArray tovar = getTovar();
			return tovar.data[index];

		}
		public TovarDataArray getTovar()
		{
			TovarDataArray tovarData = new TovarDataArray();
			Stream streamout = new FileStream(nameFile, FileMode.Open, FileAccess.Read);
			if (streamout.Length == 0)
			{
				streamout.Close();
				return tovarData;
			}
			tovarData = (TovarDataArray)serializer.Deserialize(streamout);
			streamout.Close();
			return tovarData;
		}
		public TovarDataArray getTovarConsole()
		{
			int index = 0;
			TovarDataArray clientData = getTovar();
			Console.WriteLine("Номер " + "Наименование товара  " + "Цена товара  ");
			foreach (TovarData data in clientData.data)
			{
				index++;
				Console.WriteLine(index + "    " + data.name + "    " + data.price);
			}
			return clientData;
		}

		public void deleteTovar(int indexDelete)
		{
			int index = 0;
			TovarDataArray data = getTovar();
			TovarDataArray dataSetArray = new TovarDataArray();

			foreach (TovarData dataIndex in data.data)
			{
				if (index != indexDelete)
				{
					dataSetArray.data.Add(dataIndex);
				}
				index++;
			}
			using (var fs = new FileStream(nameFile, FileMode.Create))
			{

				serializer.Serialize(fs, dataSetArray);
			}
		}
	}
}
