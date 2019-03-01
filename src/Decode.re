open Json.Decode;

type queueResponse = {
  firstTrackNumberEnqueued: string,
  newQueueLength: string,
  numTracksAdded: string,
};

type currentQueue = {
  album: option(string),
  albumArtURI: string,
  artist: string,
  title: string,
  uri: string,
};

type currentQueueResponse = {
  returned: string,
  total: string,
  items: array(currentQueue),
};

type currentTrackResponse = {
  album: option(string),
  albumArtURI: string,
  albumArtURL: string,
  artist: string,
  duration: float,
  position: float,
  queuePosition: float,
  title: string,
  uri: string,
};

type currentPlayingState =
  | Paused
  | Stopped
  | Playing
  | UnknownState;

let queueResponse = json => {
  firstTrackNumberEnqueued: json |> field("FirstTrackNumberEnqueued", string),
  newQueueLength: json |> field("NewQueueLength", string),
  numTracksAdded: json |> field("NumTracksAdded", string),
};

let currentQueue = json => {
  album: json |> optional(field("album", string)),
  albumArtURI: json |> field("albumArtURI", string),
  artist: json |> field("artist", string),
  title: json |> field("title", string),
  uri: json |> field("uri", string),
};

let currentQueueResponse = json => {
  returned: json |> field("returned", string),
  total: json |> field("total", string),
  items: json |> field("items", array(currentQueue)),
};

let getWithDefault = field => Belt.Option.getWithDefault(field, "");

let currentTrackResponse = json => {
  album: json |> optional(field("album", string)),
  albumArtURI:
    getWithDefault(json |> optional(field("albumArtURI", string))),
  albumArtURL:
    getWithDefault(json |> optional(field("albumArtURL", string))),
  artist: getWithDefault(json |> optional(field("artist", string))),
  duration: json |> field("duration", Json.Decode.float),
  position: json |> field("position", Json.Decode.float),
  queuePosition: json |> field("queuePosition", Json.Decode.float),
  title: getWithDefault(json |> optional(field("title", string))),
  uri: getWithDefault(json |> optional(field("uri", string))),
};

let currentPlayingState = currentState =>
  switch (currentState) {
  | "stopped" => Stopped
  | "paused" => Paused
  | "playing" => Playing
  | _ => UnknownState
  };
